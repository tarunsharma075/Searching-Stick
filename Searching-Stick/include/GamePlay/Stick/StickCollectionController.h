#pragma once
#include<vector>
namespace GamePlay {
	namespace Collection {
		class StickCollectionModel;
		class StickCollectionView;
		struct Stick;
		enum class SearchType;
		class StickCollectionController {
		
		private:
			StickCollectionModel* stickcollectionmodel;
			StickCollectionView* stickcollectionview;
			std::vector<Stick*>Sticks;
			Collection::SearchType search;
			void IntializeSticks();
			float CalculateStickWidth();
			float CalculateStickHeight(int stickpos);
			void UpdatestickPosition();
			void ResetStickcolor();
			void IntializeSticksArrays();
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

		};
	}
}