/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_linker *shell_linker_create(t_allocator *allocator, t_shell_lexer *lexer)
{
	t_shell_linker *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->lexer = lexer;
	self->it = NULL;
	return (self);
}

void shell_linker_init(t_allocator *allocator, t_shell_linker *self)
{
	assert(allocator != NULL);
	assert(self != NULL);

	self->it = shell_lexer_get(self->lexer);
}

void shell_linker_deinit(t_allocator *allocator, t_shell_linker *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}

t_shell_linker *shell_linker_destroy(t_allocator *allocator, t_shell_linker *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
