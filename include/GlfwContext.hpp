/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GlfwContext.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:01:42 by stephane          #+#    #+#             */
/*   Updated: 2026/11/24 19:12:51 by stephane         ###   ########.fr       */
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