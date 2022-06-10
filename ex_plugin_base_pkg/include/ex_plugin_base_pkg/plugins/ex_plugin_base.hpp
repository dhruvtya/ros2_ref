#ifndef EX_PLUGIN_BASE_PKG__EX_PLUGIN_BASE_HPP_
#define EX_PLUGIN_BASE_PKG__EX_PLUGIN_BASE_HPP_

#include "string"

namespace ex_plugin_base
{
    class ExPluginBaseClass
    {
        public:
            virtual void setup(double ex_double_var) = 0;
            virtual std::string exFunction() = 0;
            virtual ~ExPluginBaseClass(){}

        protected:
            ExPluginBaseClass(){}

    };
}    // namespace ex_plugin_base

#endif     // EX_PLUGIN_BASE_PKG__EX_PLUGIN_BASE_HPP_