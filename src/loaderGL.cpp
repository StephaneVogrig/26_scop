/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaderGL.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:32:04 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 20:44:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "loaderGL.hpp"

template <typename T>
static void loadGL(T& pfn, const char* glName)
{
    pfn = reinterpret_cast<T>(glfwGetProcAddress(glName));
    if (pfn == nullptr)
    {
        throw std::runtime_error(std::string(glName) + " load failed!");
    }
}

void loadGLextensions()
{
    loadGL(pfnglGenBuffers, "glGenBuffers");
    loadGL(pfnglBindBuffer, "glBindBuffer");
    loadGL(pfnglBufferData, "glBufferData");
    loadGL(pfnglCreateShader, "glCreateShader");
    loadGL(pfnglShaderSource, "glShaderSource");
    loadGL(pfnglCompileShader, "glCompileShader");
    loadGL(pfnglGetShaderiv, "glGetShaderiv");
    loadGL(pfnglGetShaderInfoLog, "glGetShaderInfoLog");
    loadGL(pfnglCreateProgram, "glCreateProgram");
    loadGL(pfnglAttachShader, "glAttachShader");
    loadGL(pfnglLinkProgram, "glLinkProgram");
    loadGL(pfnglGetProgramiv, "glGetProgramiv");
    loadGL(pfnglGetProgramInfoLog, "glGetProgramInfoLog");
    loadGL(pfnglDeleteShader, "glDeleteShader");
    loadGL(pfnglUseProgram, "glUseProgram");
    loadGL(pfnglVertexAttribPointer, "glVertexAttribPointer");
    loadGL(pfnglEnableVertexAttribArray, "glEnableVertexAttribArray");
    loadGL(pfnglGenVertexArrays, "glGenVertexArrays");
    loadGL(pfnglBindVertexArray, "glBindVertexArray");
    loadGL(pfnglDeleteVertexArrays, "glDeleteVertexArrays");
    loadGL(pfnglDeleteBuffers, "glDeleteBuffers");
    loadGL(pfnglDeleteProgram, "glDeleteProgram");
}
