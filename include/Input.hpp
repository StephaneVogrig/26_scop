/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 00:14:34 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 13:21:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Input_HPP
# define Input_HPP

# include <array>
# include <cstdint>
# include <GLFW/glfw3.h>

class Input
{
    public:
        enum KeyState : std::uint8_t
        {
            None         = 0,
            Down         = 1 << 0,
            JustPressed  = 1 << 1,
            JustReleased = 1 << 2
        };

        Input() = default;
        ~Input() = default;
        Input(const Input&) = delete;
        Input& operator=(const Input&) = delete;
        Input(Input&&) = delete;
        Input& operator=(Input&&) = delete;

        void endFrame();
        void onKeyEvent(int key, int action);

        bool isKeyDown(int key) const;
        bool isKeyPressed(int key) const;
        bool isKeyReleased(int key) const;

    private:
        static constexpr int MAX_KEYS = GLFW_KEY_LAST + 1;
        std::array<std::uint8_t, MAX_KEYS> _keys{};

        static bool isValidKey(int key);
        bool isKeyInState(int key, KeyState state) const;
};

#endif
