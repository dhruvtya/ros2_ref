#include "ex_plugins_pkg/plugins/ex_plugin_2.hpp"
#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(example_plugins::ExPlugin2Class, ex_plugin_base::ExPluginBaseClass)

namespace example_plugins
{
    
void ExPlugin2Class::setup(double ex_double_var){
    ex_double_var_2_ = ex_double_var;
}

std::string ExPlugin2Class::exFunction(){
    return "The second (No. " + std::to_string(ex_double_var_2_) + ") example plugin";
}

}  //namespace example_plugins