//
//  MyDatePickerController.h
//  CostList
//
//  
//

#import <UIKit/UIKit.h>

@class MyDatePickerController;

//定义协议和方法
@protocol MyDatePickerControllerDelegate <NSObject>

-(void)myDatePickerController:(MyDatePickerController *)controller didChooseDate:(NSString *)date;

@end

@interface MyDatePickerController : UIViewController


@property (nonatomic,weak) id <MyDatePickerControllerDelegate> delegate;//指向代理
@property (nonatomic,strong) NSString *currentDate;
@property (nonatomic,strong) UIView *background;    //半透明黑色背景

@end
