#!/usr/bin/env python3

import sys
import numpy
import re
import os

def Usage():
    print("USAGE")
    print("    ./autoCompletion dictionary\n")
    print("DESCRIPTION")
    print("    dictionary file containing one address per line, as knowledge base")

def check_invalid_addresses(adress):
    line = re.match(r"(?P<city>[\w '-]+)(,|) (?P<number>\d+) (?P<streetType>\w+) (?P<streetName>[\w '-]+)", adress)
    streetTypes = ['allée', 'avenue', 'boulevard', 'chemin', 'impasse', 'place', 'quai', 'rue', 'square']

    if not line or line['streetType'].lower() not in streetTypes:
        return False
    return True

def add_coma(adress):
    res = ""
    coma = 0
    for x in range(len(adress)):
        if adress[x] == ' ' and coma == 0:
            res = res + ", "
            coma += 1
        else:
            res = res + adress[x]
    return res

def get_addresses(argv):
    if os.path.getsize(argv[1]) == 0:
        print("Invalid argument")
        exit(84)
    dictionary = open(argv[1], 'r')
    address_list = []
    for line in dictionary.readlines():
        address = line.strip()
        if address.count(',') != 1:
            address = add_coma(address)
        if check_invalid_addresses(address) == False:
            print(line.strip())
        elif address_list.count(address.lower()) != 0:
            continue
        else:
            address_list.append("{}".format(address.lower()))
    return address_list

def get_original_addresses(argv):
    dictionary = open(argv[1], 'r')
    lines = dictionary.readlines()
    address_list = []
    for line in lines:
        if check_invalid_addresses(line.strip()) == True:
            address_list.append("{}".format(line.strip()))
    address_list.sort()
    return address_list

def fill_city(adr):
    res = []
    for x in range(len(adr)):
        first_word = ""
        for i in adr[x]:
            if i == ',':
                break
            first_word = first_word + i
        res.append(first_word)
    return res

def fill_number(adr):
    res = []
    for x in range(len(adr)):
        to_add = ""
        number = adr[x].find(", ") + 2
        while adr[x][number] != " ":
            to_add = to_add + adr[x][number]
            number += 1
        res.append(to_add)
    return res

def fill_streetType(adr, number):
    res = []
    for x in range(len(adr)):
        to_add = ""
        streetType = adr[x].find(number[x]) + len(number[x]) + 1
        while adr[x][streetType] != " ":
            to_add = to_add + adr[x][streetType]
            streetType += 1
        res.append(to_add)
    return res

def fill_streetName(adr, streetType):
    res = []
    for x in range(len(adr)):
        to_add = ""
        streetName = adr[x].find(streetType[x]) + len(streetType[x]) + 1
        while streetName != len(adr[x]) :
            to_add = to_add + adr[x][streetName]
            streetName += 1
        res.append(to_add)
    return res

def parse_adress(adr):
    my_list = []
    my_list.append(fill_city(adr))
    my_list.append(fill_number(adr))
    my_list.append(fill_streetType(adr, my_list[1]))
    my_list.append(fill_streetName(adr, my_list[2]))
    return my_list

def display_list_of_list(my_list):
    for x in range(len(my_list)):
        for i in range(len(my_list[x])):
            print(my_list[x][i])

def search_match(my_list, search):
    res = []
    for x in range(len(my_list)):
        if my_list[x].startswith(search):
            res.append(my_list[x])
    return res

def check_if_exist(string, final):
    exist = False
    for i in final:
        if final[i] == string:
            exist = True
    return exist

def convert_letters_to_uppercase(res):
    if len(res) == 1:
        return res
    same_letter = ""
    final_unsorted = []
    final_sorted = []
    if len(res) == 2:
        for x in range(len(res[0])):
            if res[0][x] == res[1][x]:
                same_letter = same_letter + res[0][x]
            else:
                break
    else:
        i = 0
        check = True
        current = ''
        while check != False:
            x = 0
            current = res[x][i]
            while x != len(res):
                if res[x][i] != current:
                    check = False
                x += 1
            if check == True:
                same_letter = same_letter + current
            i += 1
    for x in range(len(res)):
        to_append = same_letter.upper()
        size_of_to_append = len(same_letter)
        while size_of_to_append != len(res[x]):
            to_append = to_append + res[x][size_of_to_append]
            size_of_to_append += 1
        final_unsorted.append(to_append)
    final_sorted = sort_descending_order(final_unsorted)
    return final_sorted

def count_uppercase_in_res(res):
    count = 0
    for x in range(len(res)):
        if res[x].isupper() == True:
            count += 1
        else:
            return count

def set_letter_list(res, to_propose):
    letters = []
    for x in range(len(res)):
        for i in range(len(res[x])):
            if (res[x][i].islower()):
                if (letters.count(res[x][i]) == 0):
                    letters.append(res[x][i])
                break
    return letters

def print_uppercase(res):
    uppercase = ""
    for x in range(len(res[0])):
        if res[0][x].isupper() == True or res[0][x] == ' ' or res[0][x] == '-':
            uppercase = uppercase + res[0][x]
        else:
            break
    print(uppercase, end="")

def update_word(res):
    new = ""
    for x in range(len(res[0])):
        if res[0][x].isupper() == True or res[0][x] == ' ' or res[0][x] == '-':
            new = new + res[0][x].lower()
        else:
            break
    return new

def print_propositions_city(res):
        to_propose = count_uppercase_in_res(res)
        letter_list = set_letter_list(res, to_propose)

        for x in range(len(letter_list)):
            if (x == 5):
                break
            print('{', end="")
            print_uppercase(res)
            print(letter_list[x], end ="")
            if x == len(letter_list) - 1:
                print('}')
            else:
                print('}', end=" ")

def len_letter_list(res):
        to_propose = count_uppercase_in_res(res)
        letter_list = set_letter_list(res, to_propose)

        return len(letter_list)

def print_propositions_streetName(res, city):
        to_propose = count_uppercase_in_res(res)
        letter_list = set_letter_list(res, to_propose)
        for x in range(len(letter_list)):
            if (x == 5):
                break
            print('{', end="")
            print(city[0].upper() + ", ", end="")
            print_uppercase(res)
            print(letter_list[x], end ="")
            if x == len(letter_list) - 1:
                print('}')
            else:
                print('}', end=" ")

def clean_occurences(res):
    new = []
    for x in range(len(res)):
        if new.count(res[x]) == 0:
            new.append(res[x])
    return new

def update_list_for_city_choosen(my_list, ref):
    new = []
    city = []
    number = []
    streetType = []
    streetName = []
    for x in range(len(my_list[0])):
        if my_list[0][x] == ref[0]:
            city.append(my_list[0][x])
            number.append(my_list[1][x])
            streetType.append(my_list[2][x])
            streetName.append(my_list[3][x])
    new.append(city)
    new.append(number)
    new.append(streetType)
    new.append(streetName)
    return new

def update_list_for_streetName_choosen(my_list, ref):
    new = []
    city = []
    number = []
    streetType = []
    streetName = []
    for x in range(len(my_list[3])):
        if my_list[3][x] == ref[0]:
            city.append(my_list[0][x])
            number.append(my_list[1][x])
            streetType.append(my_list[2][x])
            streetName.append(my_list[3][x])
    new.append(city)
    new.append(number)
    new.append(streetType)
    new.append(streetName)
    return new

def print_final_proposition(my_list):
    for i in range(len(my_list[0])):
        if i == len(my_list[0]) - 1:
            print("{" + str(i + 1) + " : " + my_list[0][i].upper() + ", " + my_list[1][i] + " " + my_list[2][i].upper() + " " + my_list[3][i].upper() + "}")
        else:
            print("{" + str(i + 1) + " : " + my_list[0][i].upper() + ", " + my_list[1][i] + " " + my_list[2][i].upper() + " " + my_list[3][i].upper() + "}", end=" ")

def final_choice(my_list, val):
    res = []
    city = []
    number = []
    streetType = []
    streetName = []
    city.append(my_list[0][val - 1])
    number.append(my_list[1][val - 1])
    streetType.append(my_list[2][val - 1])
    streetName.append(my_list[3][val - 1])
    res.append(city)
    res.append(number)
    res.append(streetType)
    res.append(streetName)
    return res

def print_final_res(my_list, original_adr):
    res = []
    for x in range(len(original_adr[0])):
        if (original_adr[0][x].lower() == my_list[0][0] and
            original_adr[1][x] == my_list[1][0] and
            original_adr[2][x].lower() == my_list[2][0] and
            original_adr[3][x].lower() == my_list[3][0]):
            res.append(original_adr[0][x])
            res.append(original_adr[1][x])
            res.append(original_adr[2][x])
            res.append(original_adr[3][x])
    print("=> " + res[0] + ", " + res[1] + " " + res[2] + " " + res[3])


def sort_descending_order(res):
    sort = sorted(res, key = res.count, reverse = True)
    letter_list = []
    res = []
    for x in range(len(sort)):
        letter_list.append(sort[x][0])
    max_occurence = letter_list.count(max(letter_list, key=letter_list.count))
    while max_occurence != 0:
        for x in range(len(sort)):
            if letter_list.count(sort[x][0]) == max_occurence:
                res.append(sort[x])
        max_occurence -= 1
    return clean_occurences(res)

def loop(my_list, original_adr):
    word = ""
    city = sort_descending_order(my_list[0])
    step = 1
    if len(city) == 1:
        step = 2
        my_list = update_list_for_city_choosen(my_list, city)
        streetName = sort_descending_order(my_list[3])
        if len(streetName) == 1:
            step = 3
            my_list = update_list_for_streetName_choosen(my_list, streetName)
            streetName = convert_letters_to_uppercase(streetName)
            word = update_word(streetName)
    if len_letter_list(city) == 1:
        city = convert_letters_to_uppercase(city)
        word = update_word(city)
    while 42:
        if (step == 1):
            print_propositions_city(city)
            val = input("").lower()
            word = word + val
            city = search_match(my_list[0], word)
            city = clean_occurences(city)
            if city == []:
                print("Unknown address")
                exit(84)
            city = convert_letters_to_uppercase(city)
            word = update_word(city)
            if (len(city) == 1):
                step = 2
                word = ""
                my_list = update_list_for_city_choosen(my_list, city)
                if len(my_list[0]) == 1 or len(my_list[0]) == 2:
                    step = 3
                streetName = sort_descending_order(my_list[3])
        if (step == 2):
            print_propositions_streetName(streetName, city)
            val = input("").lower()
            word = word + val
            streetName = search_match(my_list[3], word)
            streetName = clean_occurences(streetName)
            if streetName == []:
                print("Unknown address")
                exit(84)
            streetName = convert_letters_to_uppercase(streetName)
            word = update_word(streetName)
            if len(streetName) == 1:
                step = 3
                my_list = update_list_for_streetName_choosen(my_list, streetName)
        if (step == 3):
            if len(my_list[0]) == 1:
                print_final_res(my_list, original_adr)
                exit(0)
            else:
                print_final_proposition(my_list)
                val = input("")
                if int(val) < 1 or int(val) > len(my_list):
                    print("Unknown address")
                    exit(84)
                my_list = final_choice(my_list, int(val))
                print_final_res(my_list, original_adr)
                exit(0)

if len(sys.argv) == 2 and sys.argv[1] == "-h":
    Usage()
    exit(0)

elif len(sys.argv) != 2:
    print("Invalid arguments")
    exit(84)

else:
    adr = get_addresses(sys.argv)
    o_adr = get_original_addresses(sys.argv)
    adr.sort()
    o_adr.sort()
    my_list = parse_adress(adr)
    original_adr = parse_adress(o_adr)
    loop(my_list, original_adr)