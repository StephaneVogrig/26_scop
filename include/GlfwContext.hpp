/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig < svogrig@studebt.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:01:42 by stephane          #+#    #+#             */
/*   Updated: 2026/11/24 20:59:04 by svogrig          ###   ########.fr       */
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
};

#endif
