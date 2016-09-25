'use strict';

module.exports = radix;

function radix(input) {
  const maxWidth = input.reduce(compareMaxWidth, 0);
  const widths = range(maxWidth);
  return widths.reduce(applyRadix, input);
}

function range(length) {
  return [...Array(length).keys()];
}

function applyRadix(input, width) {
  const radix = Math.pow(10, width);
  const queues = input.reduce(splitByQueues(radix), []);
  return queues.reduce(sortByPopping, []);
}

function compareMaxWidth(previousMaxWidth, actualMember) {
  const actualNumberWidth = String(actualMember).length;

  if (previousMaxWidth < actualNumberWidth) {
    return actualNumberWidth;
  }

  return previousMaxWidth;
}

function splitByQueues (radix) {
  return (queues, actual) => {
    const index = (Math.floor(actual / radix) % 10);

    let actualQueue = queues[index];

    if (actualQueue) {
      actualQueue.push(actual);
    } else {
      actualQueue = [actual];
    }

    queues[index] = actualQueue;
    return queues;
  };
}

function sortByPopping(sorted, actual) {
  return sorted.concat(actual);
}
