#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_listener.h>

namespace PointcloudPruning {

class Prune
{
 public:
  Prune(ros::NodeHandle& n);
  ~Prune();
  void pointcloud(const sensor_msgs::PointCloud2::ConstPtr& pointcloudIn);
  void pose(const geometry_msgs::PoseStamped& pose);
 private:
  ros::NodeHandle n_;
  ros::Publisher pcl_publisher_;
  ros::Subscriber pointcloudSub_;
  ros::Subscriber poseSub_;
  tf::TransformListener tf_listener_;
  void loadParams();
  std::vector<std::pair<std::string, double> > vehicle_tf_frames_;
  double maxDist2_;
  double store_duration_;
};

}