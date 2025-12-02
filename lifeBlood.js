class NoTheCountry {
    constructor(argument) {
        this.combinArray = argument.combinArray;
        this.combinResult = 1;
        
    }
    

    helloWorld() {
        console.log("Hello World!");
    }

    combination = () => {
        for (var n of this.combinArray) {
            this.combinResult *= n;
            
        }
        console.log(this.combinResult);
    }

    trackRobot(n = 0, w = 0, s = 0, e = 0) {
        let l = 0;
        let r = 0;

        l = n + (s * -1);
        r = w + (e * -1);

        let robotResult = [l, r];

        console.log(robotResult);
        


    }
}

const argument = {
    combinArray: [2, 3, 4, 5],
    

}

let javaIslands = new NoTheCountry(argument);

javaIslands.helloWorld()
javaIslands.combination()
javaIslands.trackRobot(-20, 10, 20)