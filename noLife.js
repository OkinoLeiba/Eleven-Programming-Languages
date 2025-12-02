var WakeRepeat = /** @class */ (function () {
    function WakeRepeat(objectHolder) {
        this.hello = objectHolder.hello;
        this.combinArray = objectHolder.combinArray;
        this.combinResult = 1;
    }
    WakeRepeat.prototype.helloWorld = function () {
        console.log(this.hello + " World!\n");
    };
    WakeRepeat.prototype.combination = function () {
        this.combinResult = this.combinArray.reduce(function (t, v) {
            return t * v;
        });
        return this.combinResult;
    };
    return WakeRepeat;
}());
var objectHolder = {
    hello: "Hello",
    combinArray: [2, 4, 5, 6]
};
var coffeeMorn = new WakeRepeat(objectHolder);
coffeeMorn.helloWorld();
coffeeMorn.combination();
