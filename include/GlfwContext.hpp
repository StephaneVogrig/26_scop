/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:01:42 by stephane          #+#    #+#             */
/*   Updated: 2026/11/25 14:30:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFWCONTEXT_HPP
# define GLFWCONTEXT_HPP

class GlfwContext
{
    public:
        GlfwContext();
        ~GlfwContext();
        GlfwContext(const GlfwContext&) = delete;
        GlfwContext& operator=(const GlfwContext&) = delete;
        GlfwContext(GlfwContext&&) = delete;
        GlfwContext& operator=(GlfwContext&&) = delete;
};

#endif
