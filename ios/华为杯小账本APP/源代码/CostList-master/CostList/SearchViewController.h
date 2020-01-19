//
//  SearchViewController.h
//  CostList
//
//  
//

#import <UIKit/UIKit.h>

@interface SearchViewController : UIViewController

@property (strong,nonatomic) DataModelHandler *dataModelHandler;    //数据处理器
@property (assign, nonatomic, getter=isLeftMenuVisible) BOOL isVisible;

@end
