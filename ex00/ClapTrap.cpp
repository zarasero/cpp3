/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:15:17 by zserobia          #+#    #+#             */
/*   Updated: 2025/02/27 17:01:32 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Конструктор по умолчанию
ClapTrap::ClapTrap() {
    this->name = "NoName";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "Constructor " << name << " ClapTrap is created" << std::endl;
}

// Конструктор с параметром
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Constructor " << name << " ClapTrap is created" << std::endl;
}

// Конструктор копирования
ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // Используем оператор присваивания
}

// Оператор присваивания
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Operator is called" << std::endl;
    if (this != &other) {  // Защита от самоприсваивания
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

// Деструктор
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
}

// Геттеры
int ClapTrap::getHitPoints() {
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints() {
    return this->energyPoints;
}

int ClapTrap::getAttackDamage() {
    return this->attackDamage;
}

// Реализация метода getName()
std::string ClapTrap::getName() {
    return this->name;
}

// Сеттеры
void ClapTrap::setHitPoints(int amount) {
    this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(int amount) {
    this->energyPoints = amount;
}

void ClapTrap::setAttackDamage(int amount) {
    this->attackDamage = amount;
}

// Функция атаки
void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints > 0) {
        if (this->energyPoints > 0) {
            this->setEnergyPoints(this->energyPoints - 1);
            std::cout << "ClapTrap " << name << " attacks " << target
                      << ", causing " << attackDamage << " points of damage!" << std::endl;
            //std::cout << "Energy points left: " << energyPoints << std::endl;
            std::cout << "Energy points left: " << this->getEnergyPoints() << std::endl;
        } else {
            std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
        }
    } else {
        std::cout << "ClapTrap " << name << " can't attack, it is dead!" << std::endl;
    }
}

// Функция получения урона
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints > 0) {
        this->setHitPoints(this->hitPoints - amount);
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
        if (this->hitPoints <= 0) {
            std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        }
    } else {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
    }
}

// Функция восстановления
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount 
                  << " HP! Remaining HP: " << hitPoints << ", Energy: " << energyPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot repair due to no energy or being out of health!" << std::endl;
    }
}
