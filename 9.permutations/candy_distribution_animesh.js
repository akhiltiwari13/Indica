function makeString(a, b) {
  let { partialString, spares } = reduceToNearestTwoByTwoPair(a, b)

  if (spares.a - spares.b > 3) {
    throw new Error("String not possible under given constraint")
  }

  switch (+spares.a) {
    case 0:
      partialString += 'a'
      break
    case 1: 
      partialString += 'ab'
      break
    case 2: 
      partialString += 'aab'
      break
    case 3: 
      partialString += 'aaba'
      break
    case 4: 
      partialString += 'aabaa'
      break
  }

  if (a >= b) { return partialString }
  else {
    // swab b's with a's and vice versa
    // the rest of the algorithm assumes a will always be greater than b
    // this is to compensate for that
    return partialString.replace(/[ab]/g, (char) => {
      return char == 'a' ? 'b' : 'a'
    })
  }
}

function reduceToNearestTwoByTwoPair(a, b) {
  let evenAs = 0, evenBs = 0

  if (a % 2 !== 0) {
    evenAs = a - 1
  }
  else {
    evenAs = a
  }

  if (b % 2 !== 0) {
    evenBs = b - 1
  }
  else {
    evenBs = b
  }

  // Make sure evenAs is always equals to evenBs
  if (evenAs > evenBs) { 
    evenAs -= evenAs - evenBs 
  }
  else {
    evenBs -= evenBs - evenAs
  }


  return {
    partialString: twoByTwo(evenAs, evenBs),
    spares: {
      a: a - evenAs,
      b: b - evenBs
    }
  }
}

function twoByTwo(a, b) {  
  let string = ''
  while(a > 0) {
    string += 'aabb'
    a -= 2
    b -= 2
  }

  return string
}

console.log(`The final string: ${makeString(6, 2)}`)