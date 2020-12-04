const fs = require('fs');

const lines = fs.readFileSync('input.txt', 'utf-8')
    .split('\n')

const requiredFields = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']
let currentFields = []
let valid = 0
let isInvalid = false

const checkValidity = (current, required) => {
    for (const tag of required) {
        if (!current.includes(tag)) {
            return false
        }
    }

    return true
}

const validate = (name, value) => {
    if (name == 'byr') {
        return (parseInt(value) >= 1920 && parseInt(value) <= 2002)
    }

    if (name == 'iyr') {
        return (parseInt(value) >= 2010 && parseInt(value) <= 2020)
    }
    
    if (name == 'eyr') {
        return (parseInt(value) >= 2020 && parseInt(value) <= 2030)
    }

    if (name == 'hgt') {
        const unit = value.slice(-2)
        const height = value.slice(0, -2)
        if (unit == 'cm') {
            return (parseInt(height) >= 150 && parseInt(height) <= 193)
        }

        if (unit == 'in') {
            return (parseInt(height) >= 59 && parseInt(height) <= 76)
        }

        return false
    }

    if (name == 'hcl') {
        if (value[0] != '#' || value.length != 7) {
            return false
        }

        for (char of value.slice(1)) {
            if ((char < 'a' || char > 'f') && (char < '0' || char > '9')) {
                return false
            }
        }

        return true

    }

    if (name == 'ecl') {
        return (value == 'amb' || value == 'blu' || value == 'brn' || value == 'gry'
                || value == 'grn' || value == 'hzl' || value == 'oth')
    }

    if (name == 'pid') {
        if (value.length != 9) {
            return false
        }

        if(isNaN(parseInt(value))) {
            return false
        }

        return true
    }

    if (name == 'cid') {
        return true
    }

    return false
}

for (const line of lines) {
    if (line.length == 0) {
        if (isInvalid) {
            isInvalid = false
        } else if (checkValidity(currentFields, requiredFields)) {
            valid++;
        }

        currentFields = []
        continue
    }

    const tags = line.split(' ')
    for (const tag of tags) {
        const [fieldName, fieldValue] = tag.split(':')

        if ( !validate(fieldName, fieldValue) ) {
            isInvalid = true
        }

        currentFields.push(fieldName)
    }
}

if (!isInvalid && checkValidity(currentFields, requiredFields)) {
    valid++
}

console.log('Valid:', valid);