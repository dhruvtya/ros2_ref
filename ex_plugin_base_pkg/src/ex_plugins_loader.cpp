#include <pluginlib/class_loader.hpp>
#include <iostream>
#include "ex_plugin_base_pkg/plugins/ex_plugin_base.hpp"

int main(int argc, char** argv){
    // To avoid unused parameter warnings
    (void) argc;
    (void) argv;

    pluginlib::ClassLoader<ex_plugin_base::ExPluginBaseClass> example_loader("ex_plugin_base_pkg", "ex_plugin_base::ExPluginBaseClass");

    try{
        std::shared_ptr<ex_plugin_base::ExPluginBaseClass> first_plugin = example_loader.createSharedInstance("example_plugins::ExPlugin1Class");
        first_plugin->setup(1.0);

        std::shared_ptr<ex_plugin_base::ExPluginBaseClass> second_plugin = example_loader.createSharedInstance("example_plugins::ExPlugin2Class");
        second_plugin->setup(2.0);

        std::cout << "Calling plugin 1 function : " << first_plugin->exFunction() << std::endl;
        std::cout << "Calling plugin 2 function : " << second_plugin->exFunction() << std::endl;

    }
    catch(pluginlib::PluginlibException &ex){
        std::cout << "The plugin failed to load for some reason. Error: " << ex.what() << std::endl;
        // Can be replaced with RCLCPP_ERROR() if this file is made into a node
    }

    return 0;
}