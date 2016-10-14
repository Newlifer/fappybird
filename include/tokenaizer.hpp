#pragma once

#include "string_utils.hpp"

namespace fappy {

        enum class TOKEN_TYPE : unsigned int
        {
                none = 0
        };

        template <typename StringType>
        class token
        {
                using string_type_t = StringType;

                public:
                token() = delete;

                explicit token(const string_type_t& str, TOKEN_TYPE tt)
                  : str_(str)
                  , tt_(tt)
                {
                }

                explicit token(string_type_t&& str, TOKEN_TYPE tt)
                  : str_(std::move(str))
                  , tt_(tt)
                {
                }

                token(const token&) = default;
                token(token&&)      = default;

                private:
                string_type_t str_;
                TOKEN_TYPE tt_;
        };

        template <typename StringType>
        class tokenaizer
        {
                using string_type_t = StringType;

                public:
                tokenaizer() = delete;

                explicit tokenaizer(const string_type_t&)
                {
                }

                explicit tokenaizer(string_type_t&&)
                {
                }

                tokenaizer(const tokenaizer&)
                {
                }

                tokenaizer(tokenaizer&&)
                {
                }

                std::vector<token<string_type_t>> tokens() const
                {
                        std::vector<token<string_type_t>> ret;
                        for (std::size_t i = 0; i < str_.size(); ++i) {
                                if(is_space(str_[i]))
                                        continue;
                                else
                                        ret.emplace_back("ololo", TOKEN_TYPE::none);
                        }
                        return ret;
                }

                private:
                string_type_t str_;
        };
}
