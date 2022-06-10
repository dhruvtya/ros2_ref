#ifndef EX_PLUGINS_PKG__EX_PLUGIN_1_HPP_
#define EX_PLUGINS_PKG__EX_PLUGIN_1_HPP_

#include "ex_plugin_base_pkg/plugins/ex_plugin_base.hpp"

namespace example_plugins
{
    class ExPlugin1Class : public ex_plugin_base::ExPluginBaseClass
    {
        private:
            double ex_double_var_1_;


        public:
            void setup(double ex_double_var);
            std::string exFunction();

    };
}  //namespace example_plugins


#endif  //EX_PLUGINS_PKG__EX_PLUGIN_1_HPP_