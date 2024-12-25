#include <iostream>
#include <cassert>

#include "block.hpp"
#include "command.hpp"
#include "color.hpp"
#include "display_symbol.hpp"

CBlock::CBlock() : _count(0) {}

bool CBlock::isValid() const
{
	assert(MAX_COUNT == _count);

	for (int i = 0; i < _count - 1; i++)
	{
		for (int j = i + 1; j < _count; j++)
		{
			if (UNSELECTED == _numbers[i]->value || UNSELECTED == _numbers[j]->value)
				continue;
			
			if (_numbers[i]->value == _numbers[j]->value)
				return false;
		}
	}
	return true;
}

bool CBlock::isFull() const
{
	for (int i = 0; i < _count; i++)
	{
		point_value_t* p_point_value = _numbers[i];
		if (nullptr == p_point_value || UNSELECTED == p_point_value->value)
			return false;
	}
	return false;
}

void CBlock::print() const
{
	std::cout << Color::Modifier(Color::BOLD, Color::BG_DEFAULT, Color::FG_RED) << PIPE << Color::Modifier() << " ";
	for (int i = 0; i < _count; i++)
	{
		auto number = *(_numbers[i]);
		if ((i + 1) % 3 == 0)
		{
			if (number.value == 0)
				std::cout << ' ' << " " << Color::Modifier(Color::BOLD, Color::BG_DEFAULT, Color::FG_RED) << PIPE << Color::Modifier() << " ";
			else
			{
				if (number.state == State::ERASED)
					std::cout << Color::Modifier(Color::BOLD, Color::BG_DEFAULT, Color::FG_GREEN) << number.value
					<< Color::Modifier() << " "
					<< Color::Modifier(Color::BOLD, Color::BG_DEFAULT, Color::FG_RED) << PIPE
					<< Color::Modifier() << " ";
				else
					std::cout << number.value << " " << Color::Modifier(Color::BOLD, Color::BG_DEFAULT, Color::FG_RED) << PIPE << Color::Modifier() << " ";	
			}
		}
		else
		{
			if (number.value == 0)
				std::cout << ' ' << " " << PIPE << " ";
			else
			{
				if (number.state == State::ERASED)
					std::cout << Color::Modifier(Color::BOLD, Color::BG_DEFAULT, Color::FG_GREEN) << number.value
					<< Color::Modifier() << " " << PIPE << " ";
				else
					std::cout << number.value << " " << PIPE << " ";
			}
		}
	}
	std::cout << std::endl;
}

void CBlock::push_back(point_value_t* point)
{
	assert(nullptr != point);
	_numbers[_count++] = point;
}