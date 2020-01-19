//
//  MonthPickerViewController.h
//  CostList
//
//  
//

#import <UIKit/UIKit.h>

@class MonthPickerViewController;

//定义协议和方法
@protocol MonthPickerViewControllerDelegate <NSObject>

-(void)monthPickerViewController:(MonthPickerViewController *)controller chooseMonthAndYear:(NSString *)yearAndMonth;

@end

@interface MonthPickerViewController : UIViewController

@property (nonatomic,weak) id <MonthPickerViewControllerDelegate> delegate;//指向代理
@property (nonatomic,strong) NSString *currentYearAndMonth;

//显示MonthPickerViewController
-(void)presentInParentViewController:(UIViewController *)parentViewController;

@end
