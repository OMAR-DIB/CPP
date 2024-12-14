/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:35:11 by odib              #+#    #+#             */
/*   Updated: 2024/12/03 10:44:12 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main(int ac, char **av){
	if (ac > 1)
	{
		for (int i = 1; i<ac;i++){			
			for (int j =0; av[i][j];j++){
				std::cout<<(char)std::toupper((char)av[i][j]);
			}
		}
	}
	else
	{
		std::cout<<"*LOUD AND UNBEARABLE FEEDBACK NOISE*";	
	}	
	std::cout << std::endl;
	return 0;
}