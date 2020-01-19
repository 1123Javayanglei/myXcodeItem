//
//  AlertEditTableViewController.h
//  CostList
//
// 
//

#import <UIKit/UIKit.h>

@class NotificationModel;
@class AlertEditTableViewController;

@protocol AlertEditTableViewControllerDelegate <NSObject>
//修改已有通知
-(void)alertEditTableViewController:(AlertEditTableViewController *)controller modifiedNotification:(NotificationModel *)model;
//添加新通知
-(void)alertEditTableViewController:(AlertEditTableViewController *)controller addNotification:(NotificationModel *)model;

@end

@interface AlertEditTableViewController : UITableViewController
@property (nonatomic,strong) NotificationModel *notificationModel;
@property (nonatomic,weak) id<AlertEditTableViewControllerDelegate> delegate;

@end
