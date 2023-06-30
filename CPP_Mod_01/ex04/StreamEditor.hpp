/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamEditor.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:21:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/04/29 19:38:37 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_EDITOR_H
#define STREAM_EDITOR_H

#include <string>
#include <iostream>
#include <fstream>

class StreamEditor {
	public:

		StreamEditor(const std::string& inFile, const std::string& strToDelete, const std::string& strToInsert);
		~StreamEditor();
		int	execute();
	
	private:
		std::string	_inFile;
		std::string	_strToDelete;
		std::string	_strToInsert;
};

#endif // STREAM_EDITOR_H
