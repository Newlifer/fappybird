#pramga once
#include <utility>
#include <vector>

namespace fappy {
        /*! \brief Dictionary base class.
         */
        template <typename StringType, typename Data>
        class idictionary
        {
                using string_type_t = StringType;
                using data_t = Data;
                
                using value_t = std::pair<string_type_t, data_t>;
                
                struct node_t
                {
                    value_t value_;
                    /*hash here...*/
                };
        public:
                idictionary()
                {}
                
                virtual ~idictionary()
                {}

                virtual data_t& operator [] (const string_type_t& key) = 0;
                virtual const data_t& operator [] (const string_type_t& key) const = 0;

                virtual data_t& at(const string_type_t& key) = 0;
                virtual const data_t& at(const string_type_t& key) const = 0;
                
                bool empty() const
                {
                    return false;
                }

                void clear()
                {
                    return;
                }

                template <typename Args...>
                /*iterator type*/ emplace(Args&&... args)
                {}
                
                std::size_t count() const
                {
                    return {};
                }
                
                /*
                iterator& find(const string_type_t& key)
                {}
                
                const_iterator& find(const string_type_t& key) const
                {}
                
                iterator& begin()
                {}
                
                const_iterator& begin() const
                {}
                
                iterator& end()
                {}
                
                const_iterator& end() const
                {}
                 */

                void rehash()
                {}

        private:
            std::vector<node_t> nodes_;
        };
}
