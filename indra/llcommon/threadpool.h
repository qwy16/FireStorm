/**
 * @file   threadpool.h
 * @author Nat Goodspeed
 * @date   2021-10-21
 * @brief  ThreadPool configures a WorkQueue along with a pool of threads to
 *         service it.
 * 
 * $LicenseInfo:firstyear=2021&license=viewerlgpl$
 * Copyright (c) 2021, Linden Research, Inc.
 * $/LicenseInfo$
 */

#if ! defined(LL_THREADPOOL_H)
#define LL_THREADPOOL_H

#include "workqueue.h"
#include <string>
#include <thread>
#include <utility>                  // std::pair
#include <vector>

namespace LL
{

    class ThreadPool
    {
    public:
        /**
         * Pass ThreadPool a string name. This can be used to look up the
         * relevant WorkQueue.
         */
        ThreadPool(const std::string& name, size_t threads=1, size_t capacity=1024);
        ~ThreadPool();
        void close();

    private:
        void run(const std::string& name);

        WorkQueue mQueue;
        std::string mName;
        std::vector<std::pair<std::string, std::thread>> mThreads;
    };

} // namespace LL

#endif /* ! defined(LL_THREADPOOL_H) */