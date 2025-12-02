class WakeRepeat {
    hello: string;
    combinArray: number[];
    combinResult: number;


    constructor(objectHolder: any) {
        this.hello = objectHolder.hello;
        this.combinArray = objectHolder.combinArray;
        this.combinResult = 1;
    }

    helloWorld(): void {
        console.log(this.hello + " World!\n");
    }

    combination(): number {
        this.combinResult = this.combinArray.reduce((t: number, v: number) => {
            return t * v;

        });
        console.log("Combination " + this.combinResult)
        return this.combinResult;
    }

    robotTracker(n: number = 0, e: number = 0, s: number = 0, w: number = 0): void {

        let l: number = 0;
        let r: number = 0;

        l = n + (s * -1);
        r = e + (w * -1);

        let robotResult: number[] = [l, r];

        console.log("Robot Track " + robotResult);

    }
}

const objectHolder: { hello: string, combinArray: Array<number> } = {
    hello: "Hello",
    combinArray: [2, 4, 5, 6]
}

let coffeeMorn = new WakeRepeat(objectHolder);

coffeeMorn.helloWorld();
coffeeMorn.combination();
coffeeMorn.robotTracker(20, 10, -20)