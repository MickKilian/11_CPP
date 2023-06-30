/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamEditor.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:27:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/06/30 18:00:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamEditor.hpp"

StreamEditor::StreamEditor(const std::string& inFile, const std::string& strToDelete,
	const std::string& strToInsert) : _inFile(inFile), _strToDelete(strToDelete),
	_strToInsert(strToInsert) {
}

StreamEditor::~StreamEditor() {
}

int	StreamEditor::execute() {
	std::string		line;
	std::ifstream	ifs(_inFile.c_str());
	size_t			pos;
	size_t			prevPos;
	int				count = 0;

	if (!ifs)
		return (-1);
	std::ofstream	ofs(_inFile.append(".replace").c_str());
	if (!ofs) {
		ifs.close();
		return (-1);
	}
	while (!ifs.eof()) {
		std::getline(ifs, line);
		pos = 0;
		while (pos != std::string::npos) {
			prevPos = pos;
			pos = line.find(_strToDelete, pos);
			ofs << line.substr(prevPos, pos - prevPos);
			if (pos != std::string::npos) {
				count++;
				ofs << _strToInsert;
				pos += _strToDelete.size();
			}
		}
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (count);
}
