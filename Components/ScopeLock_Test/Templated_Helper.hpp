#ifndef TEMPLATED_HELPER_HPP
#define TEMPLATED_HELPER_HPP

#include "Os/Mutex.hpp"
#include "Fw/Types/Assert.hpp"
#include "Os/Task.hpp"

namespace util
{
    template <typename T>
    class MyHelper
    {
        public:
            MyHelper() : my_flag(false) {}
            ~MyHelper() {}

            void Do_Long_Task()
            {
                Os::ScopeLock(this->my_mutex);
                Fw::TimeInterval interval(10, 0);

                this->my_flag = true;
                Os::Task::delay(interval);
                this->my_flag = false;
            }

            void Do_Short_Task()
            {
                Os::ScopeLock(this->my_mutex);
                FW_ASSERT(false == this->my_flag);
            }

            void SetData(T &data)
            {
                this->my_data = data;
            }

            T& GetData(void)
            {
                return this->my_data;
            }

        private:
            Os::Mutex my_mutex;
            bool my_flag;
            T my_data;
    };

    template <typename T>
    class MyTemplatedClass
    {
        public:
            MyTemplatedClass(MyHelper<T> &helper) :
                my_helper(helper)
            {
            }

            void DoCommandStuff()
            {
                this->my_helper.Do_Long_Task();
            }

            void DoRgStuff()
            {
                this->my_helper.Do_Short_Task();
            }

            void PassThroughData(T &data)
            {
                this->my_helper.SetData(data);
            }

            T& GetData()
            {
                return this->my_helper.GetData();
            }

        private:
            MyHelper<T> &my_helper;
    };

}
#endif // ! defined TEMPLATED_HELPER_HPP
