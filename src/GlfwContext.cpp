/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:04:58 by stephane          #+#    #+#             */
/*   Updated: 2026/11/24 19:14:53 by stephane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <string>
#include <GLFW/glfw3.h>
#include "GlfwContext.hpp"

GlfwContext::GlfwContext() {
    if (!glfwInit()) {
        throw(std::runtime_error("GLFW initialisation failed!"));
    }
}

GlfwContext::~GlfwContext() {
    glfwTerminate();
}
