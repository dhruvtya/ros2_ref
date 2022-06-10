#ifndef EX_PLUGINS_PKG__EX_PLUGIN_2_HPP_
#define EX_PLUGINS_PKG__EX_PLUGIN_2_HPP_

#include "ex_plugin_base_pkg/plugins/ex_plugin_base.hpp"

namespace example_plugins
{
    class ExPlugin2Class : public ex_plugin_base::ExPluginBaseClass
    {
        private:
            double ex_double_var_2_;


        public:
            void setup(double ex_double_var);
            std::string exFunction();

    };
}  //namespace example_plugins


#endif  //EX_PLUGINS_PKG__EX_PLUGIN_2_HPP_