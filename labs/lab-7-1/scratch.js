const randomBetween = (min,max) => {
    return Math.floor(Math.random()*(max-min))+min;
}

for(let i=0; i<65; i++){
    console.log(randomBetween(-5,1000));
}