//
//  MyTabBarController.h
//  CostList
//
//  
//

#import <UIKit/UIKit.h>
#import "AddItemViewController.h"

@class MyNavigationController;

@interface MyTabBarController : UITabBarController <AddItemViewControllerDelegate>

@property (strong,nonatomic) DataModelHandler *dataModelHandler;    //数据处理器

-(void)showSlideMenuController;

-(void)showAddOrEditItemControllerWithDataModel:(CostItem *)costItem;

-(MyNavigationController *)getAddItemViewControllerToPreViewForDataModel:(CostItem *)costItem;

-(void)didClickDeleteBtnInPreviewWithIndexPath:(NSIndexPath *)indexPath;

@end
