// ======================================================================
// \title  Android/SystemResources.cpp
// \author nensanders
// \brief  hpp file for SystemResources component implementation class
//
// \copyright
// Copyright 2021, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <Os/SystemResources.hpp>
#include <thread> // For std::thread::hardware_concurrency

namespace Os {

    SystemResources::SystemResourcesStatus SystemResources::getCpuCount(U32& cpu_count) {
        auto count = std::thread::hardware_concurrency(); // Get the number of CPU cores
        if (count == 0) {
            return SYSTEM_RESOURCES_ERROR;
        }
        cpu_count = static_cast<U32>(count);
        return SYSTEM_RESOURCES_OK;
    }

    SystemResources::SystemResourcesStatus SystemResources::getCpuTicks(CpuTicks& cpu_ticks, U32 cpu_index) {
        cpu_ticks.used = 1;
        cpu_ticks.total = 1;
        return SYSTEM_RESOURCES_OK;
    }

    SystemResources::SystemResourcesStatus SystemResources::getMemUtil(MemUtil& memory_util) {
        memory_util.total = 1;
        memory_util.used = 1;
        return SYSTEM_RESOURCES_OK;
    }
}
