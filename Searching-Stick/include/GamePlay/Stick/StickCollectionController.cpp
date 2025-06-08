#include "StickCollectionController.h"
#include"../../GamePlay/Stick/Stick.h"
#include"../../include/GamePlay/Stick/StickCollectionModel.h"
#include"../../include/GamePlay/Stick/StickCollectionView.h"
#include"../../include/GamePlay/Stick/Stick.h"
#include"../../include/Global/ServiceLocator.h"
#include<random>
namespace GamePlay {
	namespace Collection {
		using namespace UI::UIElement;
		using namespace Global;

		void StickCollectionController::IntializeSticks()
		{
			float rectangleWidth = CalculateStickWidth();
			for (int i = 0; i < stickcollectionmodel->number_of_elements; i++) {
				float rectangle_height = CalculateStickHeight(i);
				sf::Vector2f rectangelsize = sf::Vector2f(rectangleWidth, rectangle_height);
				Sticks[i]->stickView->initialize(rectangelsize, sf::Vector2f(0, 0), 0, stickcollectionmodel->element_color);
			}

		}
		float StickCollectionController::CalculateStickWidth()
		{
			float screenWidth = static_cast<float> (ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x);
			float  totalSpace = stickcollectionmodel->space_percentage * screenWidth;
			float spaceBetween = totalSpace / stickcollectionmodel->number_of_elements;
			stickcollectionmodel->SetElementsSpacing(spaceBetween);
			float remainingspace = screenWidth - totalSpace;
			float rectanglewidth = remainingspace / stickcollectionmodel->number_of_elements;
			return rectanglewidth;
		}
		float StickCollectionController::CalculateStickHeight(int stickpos)
		{
			return static_cast<float>(((stickpos + 1.0f) / stickcollectionmodel->number_of_elements) * stickcollectionmodel->max_element_height);

		}
		void StickCollectionController::UpdatestickPosition()
		{
			for (int i = 0; i < Sticks.size(); i++) {
				float xposition = (i * Sticks[i]->stickView->getSize().x + (i + 1) * stickcollectionmodel->elements_spacing);
				float  yposition = stickcollectionmodel->element_y_position - Sticks[i]->stickView->getSize().y;
				Sticks[i]->stickView->setPosition(sf::Vector2f(xposition, yposition));
			}
		}
		void StickCollectionController::ResetStickcolor()
		{
			for (int i = 0; i < Sticks.size(); i++) {
				Sticks[i]->stickView->setFillColor(stickcollectionmodel->element_color);
			}
		}
		void StickCollectionController::IntializeSticksArrays()
		{
			for (int i = 0; i < stickcollectionmodel->number_of_elements; i++) {
				Sticks.push_back(new Stick(i));
			}

		}
		void StickCollectionController::JoinThreads()
		{
			searchThread.join();
		}
		void StickCollectionController::SortElements()
		{
			std::sort(Sticks.begin(), Sticks.end(), [this](Stick* stick1, Stick* stick2) {
				return CompareElemenrtsBydata(stick1, stick2);
				});
			UpdatestickPosition();
		}
		bool StickCollectionController::CompareElemenrtsBydata(Stick* stick1, Stick* stick2)
		{
			return stick1->data < stick2->data;
		}
		GamePlay::Collection::StickCollectionController::StickCollectionController()
		{
			stickcollectionmodel = new StickCollectionModel();
			stickcollectionview = new StickCollectionView();
			IntializeSticksArrays();
		}

		GamePlay::Collection::StickCollectionController::~StickCollectionController()
		{
			if (searchThread.joinable()) {
				searchThread.join();

			}
			for (int i = 0; i < Sticks.size(); i++) {

				delete Sticks[i];
				Sticks.clear();
			}
			delete(stickcollectionmodel);
			delete(stickcollectionview);
		}

		void GamePlay::Collection::StickCollectionController::Intialize()
		{
			stickcollectionmodel->Intialize();
			IntializeSticks();
			reset();
		}

		void GamePlay::Collection::StickCollectionController::Update()
		{
			ProcesssearchThreads();
			for (int i = 0; i < Sticks.size(); i++)
			{
				Sticks[i]->stickView->update();
			}
		}

		void GamePlay::Collection::StickCollectionController::Render()
		{
			for (int i = 0; i < Sticks.size(); i++)
			{
				Sticks[i]->stickView->render();
			}
		}

		int GamePlay::Collection::StickCollectionController::GetNumberOfElements()
		{
			return stickcollectionmodel->number_of_elements;
		}

		Collection::SearchType GamePlay::Collection::StickCollectionController::GetSearchtype()
		{
			return search;
		}

		void StickCollectionController::SetSearchType(Collection::SearchType searchtype)
		{
			search = searchtype;
			switch (search) {
			case GamePlay::Collection::SearchType::Linear:
				timeComplexity = "O(n)";
				currentOprationDelay = stickcollectionmodel->linear_search_delay;
				searchThread = std::thread(&StickCollectionController::processLinearSearch, this);
				break;
				
			case GamePlay::Collection::SearchType::Binary:
				SortElements();
				timeComplexity = "O(log n)";
				currentOprationDelay = stickcollectionmodel->binary_search_delay;
				searchThread = std::thread(&StickCollectionController::ProcessBinarySearch, this);
				break;
			}
		}

		void StickCollectionController::reset()
		{
			ShuffleSticks();
			UpdatestickPosition();
			ResetStickcolor();
			SticktoSearch();
			resetvariables();
			currentOprationDelay = 0;
		}

		void StickCollectionController::ShuffleSticks()
		{

			std::random_device device;
			std::mt19937 random_engine(device());
			std::shuffle(Sticks.begin(), Sticks.end(), random_engine);

		}

		void StickCollectionController::SticktoSearch()
		{
			sticktoSearch = Sticks[rand() % Sticks.size()];
			sticktoSearch->stickView->setFillColor(stickcollectionmodel->search_element_color);
		}

		void StickCollectionController::processLinearSearch()
		{
			for (int i = 0; i < Sticks.size(); i++) {
				numberofarrayaccesses + 1;
				numberOfComparisons++;
				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::COMPARE_SFX);

				if (Sticks[i] == sticktoSearch) {
					sticktoSearch->stickView->setFillColor(stickcollectionmodel->found_element_color);
					sticktoSearch = nullptr;

					return;
				}
				else {
					Sticks[i]->stickView->setFillColor(stickcollectionmodel->processing_element_color);
					std::this_thread::sleep_for(std::chrono::milliseconds(currentOprationDelay));
					Sticks[i]->stickView->setFillColor(stickcollectionmodel->element_color);
				}


			}
		}

		void StickCollectionController::resetvariables()
		{
			numberofarrayaccesses = 0;
			numberOfComparisons = 0;
		}

		int StickCollectionController::GetnumberOfComparisons()
		{
			return numberOfComparisons;
		}

		int StickCollectionController::Getnumberofarrayaccess()
		{
			return numberofarrayaccesses;
		}

		int StickCollectionController::GetDelayMilliSeconds()
		{
			return currentOprationDelay;
		}

		void StickCollectionController::ProcesssearchThreads()
		{
			if (searchThread.joinable() && sticktoSearch == nullptr) {
				JoinThreads();
			}
		}

		sf::String StickCollectionController::gettimeComplexity()
		{
			return timeComplexity;
		}

		void StickCollectionController::ProcessBinarySearch()
		{
			// initialize left index to the start of the collection
			int left = 0;

			// initialize right index to the size of the collection which is the end
			int right = Sticks.size();

			Sound::SoundService* sound_service = Global::ServiceLocator::getInstance()->getSoundService();

			// loop for binary search
			while (left < right)
			{

				// calculate the middle index
				int mid = left + (right - left) / 2;
				numberofarrayaccesses += 2;				//keeps track of the number of sticks array is accessed
				numberOfComparisons++;					// keeps track of the number of comparisons made between target stick and another stick

				sound_service->playSound(Sound::SoundType::COMPARE_SFX);			// play comparison sound effect

				// check if target element is found at the middle index
				if (Sticks[mid] == sticktoSearch)
				{
					// if the target element is found, set color for found element
					Sticks[mid]->stickView->setFillColor(stickcollectionmodel->found_element_color);			// sets the color of the found element to found_element_color
					sticktoSearch = nullptr;			//ets the pointer to null; meaning the search is completed
					return;
				}

				Sticks[mid]->stickView->setFillColor(stickcollectionmodel->processing_element_color);		// if mid is not the target element, set the stick color to processing element color
				std::this_thread::sleep_for(std::chrono::milliseconds(currentOprationDelay));			// //pauses the thread for a small duration to show the searching operation
				Sticks[mid]->stickView->setFillColor(stickcollectionmodel->element_color);	// sets the fill color of the mid stick's view back to the default element_color after the pause.


				numberofarrayaccesses++;			// increment counter for array access for mid element access

				// target can be in the right half or middle element itself
				if (Sticks[mid]->data <= sticktoSearch->data) left = mid;				// target must be in the right half, mid element included beacuse '<='
				else right = mid;
			}

		}
	}
}

