#include "ex_plugins_pkg/plugins/ex_plugin_1.hpp"
#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(example_plugins::ExPlugin1Class, ex_plugin_base::ExPluginBaseClass)

namespace example_plugins
{
    
void ExPlugin1Class::setup(double ex_double_var){
    ex_double_var_1_ = ex_double_var;
}

std::string ExPlugin1Class::exFunction(){
    return "The first (No. " + std::to_string(ex_double_var_1_) + ") example plugin";
}

}  //namespace example_plugins