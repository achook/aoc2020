const fs = require('fs');

const lines = fs.readFileSync('input.txt', 'utf-8')
    .split('\n')

const requiredFields = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'];
let currentFields = []
let valid = 0

const checkValidity = (current, required) => {
    for (const tag of required) {
        if (!current.includes(tag)) {
            return false
        }
    }

    return true
}

for (const line of lines) {
    if (line.length == 0) {
        if (checkValidity(currentFields, requiredFields)) {
            valid++;
        }

        currentFields = []
        continue
    }

    const tags = line.split(' ')
    for (const tag of tags) {
        const fieldName = tag.split(':')[0]
        currentFields.push(fieldName)
    }
}

if (checkValidity(currentFields, requiredFields)) {
    valid++
}

console.log('Valid:', valid);