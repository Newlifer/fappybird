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

                token(const string_type_t& str, TOKEN_TYPE tt)
                  : str_(str)
                  , tt_(tt)
                {
                }

                token(string_type_t&& str, TOKEN_TYPE tt)
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
                using string_vec_t = std::vector<token<string_type_t>>;

                public:
                tokenaizer() = delete;

                explicit tokenaizer(const string_type_t&)
                {
                }

                explicit tokenaizer(string_type_t&&)
                {
                }

                explicit tokenaizer(const tokenaizer&)
                {
                }

                tokenaizer(tokenaizer&&)
                {
                }

                string_vec_t make_tokens() const
                {
                        std::vector<token<string_type_t>> ret;
                        std::size_t last_pos = 0u;
                        for (std::size_t i = 0; i < str_.size(); ++i) {
                                if(is_space(str_[i]))
                                        continue;
                                else
                                        ret.emplace_back("ololo", TOKEN_TYPE::none);
                        }
                        return ret;
                }
                
                void tokenize()
                {
                    this->tokens_ = this->make_tokens();
                }
                
                const string_vec_t& tokens() const
                {
                    return this->tokens_;
                }
                
                string_vec_t& tokens()
                {
                    return this->tokens_;
                }

                private:
                string_type_t str_;
                string_vec_t tokens_;
        };
}
