const randomBetween = (min,max) => {
    return Math.floor(Math.random()*(max-min))+min;
}

for(let i=0; i<=50; i++){
    console.log(randomBetween(1,1000));
}