#pragma once

#include <cstring>
#include <stdexcept>
#include <string>

#include "string_utils.hpp"

namespace fappy {
        class fixed_string_length_exception : public std::runtime_error
        {
                public:
                fixed_string_length_exception(const char* msg)
                  : std::runtime_error(msg)
                {
                }
        };

        /*! \brief Fixed length basic string class.
         * \tparam CharT Char type.
         * \tparam Size Size of string.
         */
        template <typename CharT, std::size_t Size>
        class basic_fixed_string
        {
                using chart_type          = CharT;
                using variable_len_string = std::basic_string<chart_type>;

                public:
                basic_fixed_string()
                  : length_(0)
                {
                        std::memset(chars_, 0, Size);
                }

                basic_fixed_string(const chart_type* chars)
                {
                        length_ = std::min(Size, std::strlen(chars) + 1);
                        std::memcpy(chars_, chars, sizeof(chart_type) * length_);
                }

                /*! \brief Constructor from variadic length string (aka \link std::basic_string).
                 */
                basic_fixed_string(const variable_len_string& other)
                {
                        const auto size = std::min(Size, other.size());
                        this->copy(size, other.data());
                }

                basic_fixed_string(const basic_fixed_string& other)
                {
                        std::memcpy(chars_, other.chars_, sizeof(chart_type) * Size);
                }

                basic_fixed_string(basic_fixed_string&& /*other*/)
                {
                }

                basic_fixed_string& operator=(const basic_fixed_string& other)
                {
                        if (other != *this) {
                                copy(other.size(), other.chars_);
                                return *this;
                        } else {
                                return *this;
                        }
                }

                basic_fixed_string& operator=(const chart_type* other)
                {
                        if (!(*this == other)) {
                                copy(std::min(std::strlen(other), max_size()), other);
                                return *this;
                        } else {
                                return *this;
                        }
                }

                chart_type& operator[](std::size_t index)
                {
                        return chars_[index];
                }

                const chart_type& operator[](std::size_t index) const
                {
                        return chars_[index];
                }

                /*! \brief Current string size (not null chars).
                 */
                std::size_t size() const
                {
                        return length_;
                }

                /*! \brief Maximum string length.
                 */
                constexpr std::size_t max_size() const
                {
                        return Size;
                }

                const chart_type* raw() const
                {
                        return chars_;
                }

                variable_len_string substr(std::size_t start, std::size_t len) const
                {
                        if (start >= this->length_)
                                throw fixed_string_length_exception(
                                  "Cannot get substring from start position that more than string lenth!");
                        const auto len__ = std::min(this->length_ - start, len + 1);
                        variable_len_string ret(chars_ + start, chars_ + (start + len__));
                        return ret;
                }

                variable_len_string as_std_string() const
                {
                        return variable_len_string(chars_, chars_ + length_);
                }

                bool operator==(const chart_type* other) const
                {
                        if (std::strlen(other) != this->length_)
                                return false;
                        else
                                return std::memcmp(chars_, other, length_) == 0;
                }

                bool operator==(const basic_fixed_string& other) const
                {
                        return other == chars_;
                }

                bool operator!=(const basic_fixed_string& other) const
                {
                        return !(other == this->chars_);
                }

                /*! \brief Strips all whitespaces from left.
                 */
                inline void strip_left()
                {
                        std::size_t i = 0;
                        for (; i < this->size(); ++i)
                                if (!is_space(this->chars_[i]))
                                        break;
                        if (i <= this->size())
                                this->shift_left(i);
                }

                /*! \brief Strips all whitespaces from right.
                 */
                inline void strip_right()
                {
                        std::size_t i = this->size() - 1;
                        for (; i > 0; i--)
                                if (!is_space(this->chars_[i]))
                                        break;
                        this->length_ = i + 1;
                        std::memset(this->chars_ + this->size(), 0,
                                    sizeof(chart_type) * this->max_size() - this->size());
                }

                /*! \brief Strips all whitespaces from right and left.
                 */
                void trim()
                {
                        this->strip_left();
                        this->strip_right();
                }

                void shift_left(const std::size_t val)
                {
                        for (std::size_t i            = val; i < this->size(); ++i)
                                this->chars_[i - val] = this->chars_[i];
                        this->length_                 = this->size() - val;
                        std::memset(this->chars_ + this->size(), 0, sizeof(chart_type) * this->size());
                }

                template <class CharT_, std::size_t Size_>
                friend std::ostream& operator<<(std::ostream& stream, const basic_fixed_string<CharT_, Size_>& str);

                private:
                void copy(const std::size_t size, const chart_type* chars)
                {
                        this->length_ = size;
                        std::memcpy(this->chars_, chars, sizeof(chart_type) * this->length_);
                }

                chart_type chars_[Size];
                std::size_t length_;
        };

        /*! \brief Fixed string with `char' type base template alias.
         */
        template <std::size_t Size>
        using fixed_string_char = basic_fixed_string<char, Size>;

        template <typename CharT, std::size_t Size>
        std::ostream& operator<<(std::ostream& stream, const basic_fixed_string<CharT, Size>& str)
        {
                stream << str.chars_;
                return stream;
        }
}
