/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 00:44:58 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 13:25:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

bool Input::isValidKey(int key)
{
    return (key >= 0) && (key < MAX_KEYS);
}

void Input::endFrame()
{
    constexpr std::uint8_t stableKeyMask = static_cast<std::uint8_t>(~(KeyState::JustPressed | KeyState::JustReleased));

    for (std::uint8_t& state : _keys)
    {
        state &= stableKeyMask;
    }
}

void Input::onKeyEvent(int key, int action)
{
    if (!isValidKey(key))
    {
        return;
    }

    uint8_t& state = _keys[static_cast<std::size_t>(key)];

    // GLFW_REPEAT is intentionally ignored:
    // the key is already marked Down since the initial PRESS,
    // and OS auto-repeat events must not retrigger JustPressed.
    if (action == GLFW_PRESS)
    {
        state = static_cast<std::uint8_t>(KeyState::Down | KeyState::JustPressed);
    }
    else if (action == GLFW_RELEASE)
    {
        state = static_cast<std::uint8_t>(KeyState::JustReleased);
    }
}

bool Input::isKeyInState(int key, KeyState state) const
{
    if (!isValidKey(key))
    {
        return false;
    }
    return (_keys[static_cast<std::size_t>(key)] & state) != 0;
}

bool Input::isKeyDown(int key) const
{
    return isKeyInState(key, KeyState::Down);
}

bool Input::isKeyPressed(int key) const
{
    return isKeyInState(key, KeyState::JustPressed);
}

bool Input::isKeyReleased(int key) const
{
    return isKeyInState(key, KeyState::JustReleased);
}
