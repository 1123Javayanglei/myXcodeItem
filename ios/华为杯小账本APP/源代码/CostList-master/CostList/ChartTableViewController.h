//
//  ChartTableViewController.h
//  CostList
//
// 
//

#import <UIKit/UIKit.h>

@interface ChartTableViewController : UIViewController <UITableViewDelegate,UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UIButton *monthPickerButton;  //月份选择器按钮

@property (strong,nonatomic) DataModelHandler *dataModelHandler;    //数据处理器

@end
