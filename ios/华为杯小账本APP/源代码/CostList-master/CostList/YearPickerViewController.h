//
//  YearPickerViewController.h
//  CostList
//
//  
//

#import <UIKit/UIKit.h>

@class YearPickerViewController;

//定义协议和方法
@protocol YearPickerViewControllerDelegate <NSObject>

-(void)yearPickerViewController:(YearPickerViewController *)controller chooseYear:(NSString *)year;

@end

@interface YearPickerViewController : UIViewController

@property (nonatomic,weak) id <YearPickerViewControllerDelegate> delegate;//指向代理
@property (nonatomic,strong) NSString *currentYear;

//显示YearPickerViewController
-(void)presentInParentViewController:(UIViewController *)parentViewController;

@end
