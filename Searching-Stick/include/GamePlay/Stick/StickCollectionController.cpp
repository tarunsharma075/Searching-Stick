#include "StickCollectionController.h"
#include"../../GamePlay/Stick/Stick.h"
#include"../../include/GamePlay/Stick/StickCollectionModel.h"
#include"../../include/GamePlay/Stick/StickCollectionView.h"
#include"../../include/GamePlay/Stick/Stick.h"
#include"../../include/Global/ServiceLocator.h"
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
			for (int i = 0; i < stickcollectionmodel->number_of_elements; i++){
				Sticks.push_back(new Stick(i));
		}

		}
		GamePlay::Collection::StickCollectionController::StickCollectionController()
		{
			stickcollectionmodel = new StickCollectionModel();
			stickcollectionview = new StickCollectionView();
			IntializeSticksArrays();
		}

		GamePlay::Collection::StickCollectionController::~StickCollectionController()
		{
		}

		void GamePlay::Collection::StickCollectionController::Intialize()
		{
			IntializeSticks();
			reset();
		}

		void GamePlay::Collection::StickCollectionController::Update()
		{
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
			
		}

		void StickCollectionController::reset()
		{
			ResetStickcolor();
			UpdatestickPosition();
		}

	}
}

