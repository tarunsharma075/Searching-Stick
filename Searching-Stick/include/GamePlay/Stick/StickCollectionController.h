#pragma once
#include<vector>
#include<thread>
namespace GamePlay {
	namespace Collection {
		class StickCollectionModel;
		class StickCollectionView;
		struct Stick;
		enum class SearchType;
		class StickCollectionController {
			Stick* sticktoSearch;
		private:
			StickCollectionModel* stickcollectionmodel;
			StickCollectionView* stickcollectionview;
			int currentOprationDelay;
			std::thread searchThread;
			std::vector<Stick*>Sticks;
			Collection::SearchType search;
			void IntializeSticks();
			float CalculateStickWidth();
			float CalculateStickHeight(int stickpos);
			void UpdatestickPosition();
			void ResetStickcolor();
			void IntializeSticksArrays();
			int numberOfComparisons;
			int numberofarrayaccesses;
			void JoinThreads();
		public:
			StickCollectionController();
			~StickCollectionController();
			
			void Intialize();
			void Update();
			void Render();
			int GetNumberOfElements();
			Collection::SearchType GetSearchtype();
			
			void SetSearchType(Collection::SearchType searchtype);
			void reset();
			void ShuffleSticks();
			void SticktoSearch();
			void processLinearSearch();
			void resetvariables();
			int GetnumberOfComparisons();
			int Getnumberofarrayaccess();
			int GetDelayMilliSeconds();
			void ProcesssearchThreads();
		};
	}
}