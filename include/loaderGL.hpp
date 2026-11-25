/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaderGL.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:48:46 by svogrig           #+#    #+#             */
/*   Updated: 2026/11/25 20:44:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLLOADER_HPP
# define GLLOADER_HPP

# define GLFW_INCLUDE_GLEXT
# include <GLFW/glfw3.h>


inline PFNGLCREATESHADERPROC            pfnglCreateShader;
inline PFNGLSHADERSOURCEPROC            pfnglShaderSource;
inline PFNGLCOMPILESHADERPROC           pfnglCompileShader;
inline PFNGLGETSHADERIVPROC             pfnglGetShaderiv;
inline PFNGLGETSHADERINFOLOGPROC        pfnglGetShaderInfoLog;
inline PFNGLCREATEPROGRAMPROC           pfnglCreateProgram;
inline PFNGLATTACHSHADERPROC            pfnglAttachShader;
inline PFNGLLINKPROGRAMPROC             pfnglLinkProgram;
inline PFNGLGETPROGRAMIVPROC            pfnglGetProgramiv;
inline PFNGLGETPROGRAMINFOLOGPROC       pfnglGetProgramInfoLog;
inline PFNGLDELETESHADERPROC            pfnglDeleteShader;
inline PFNGLGENBUFFERSPROC              pfnglGenBuffers;
inline PFNGLBINDBUFFERPROC              pfnglBindBuffer;
inline PFNGLBUFFERDATAPROC              pfnglBufferData;
inline PFNGLUSEPROGRAMPROC              pfnglUseProgram;
inline PFNGLVERTEXATTRIBPOINTERPROC     pfnglVertexAttribPointer;
inline PFNGLENABLEVERTEXATTRIBARRAYPROC pfnglEnableVertexAttribArray;
inline PFNGLGENVERTEXARRAYSPROC         pfnglGenVertexArrays;
inline PFNGLBINDVERTEXARRAYPROC         pfnglBindVertexArray;
inline PFNGLDELETEVERTEXARRAYSPROC      pfnglDeleteVertexArrays;
inline PFNGLDELETEBUFFERSPROC           pfnglDeleteBuffers;
inline PFNGLDELETEPROGRAMPROC           pfnglDeleteProgram;

# define glGenBuffers               pfnglGenBuffers
# define glBindBuffer               pfnglBindBuffer
# define glBufferData               pfnglBufferData
# define glCreateShader             pfnglCreateShader
# define glShaderSource             pfnglShaderSource
# define glCompileShader            pfnglCompileShader
# define glGetShaderiv              pfnglGetShaderiv
# define glGetShaderInfoLog         pfnglGetShaderInfoLog
# define glCreateProgram            pfnglCreateProgram
# define glAttachShader             pfnglAttachShader
# define glLinkProgram              pfnglLinkProgram
# define glGetProgramiv             pfnglGetProgramiv
# define glGetProgramInfoLog        pfnglGetProgramInfoLog
# define glDeleteShader             pfnglDeleteShader
# define glUseProgram               pfnglUseProgram
# define glVertexAttribPointer      pfnglVertexAttribPointer
# define glEnableVertexAttribArray  pfnglEnableVertexAttribArray
# define glGenVertexArrays          pfnglGenVertexArrays
# define glBindVertexArray          pfnglBindVertexArray
# define glDeleteVertexArrays       pfnglDeleteVertexArrays
# define glDeleteBuffers            pfnglDeleteBuffers
# define glDeleteProgram            pfnglDeleteProgram

void loadGLextensions();

#endif
