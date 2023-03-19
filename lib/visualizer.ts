interface Visualizer<T> {
  prevDatas: T[];
  compareDiff(): boolean[];
  printDiff(): void;
};

const compareArrDiff = (arrBefore: number[], arrAfter: number[]): boolean[] =>
  arrBefore.map((value, i) => arrBefore[i] === arrAfter[i] ? true : false);

const printArrDiff = (arrBefore: number[], arrAfter: number[], step: number): void => {
  const flags: boolean[] = compareArrDiff(arrBefore, arrAfter);
  let logsBefore: string = '[';
  let logsAfter: string = '[';
  if (!arrBefore || !arrAfter) {
    console.log('length of each arrays are different.');
    return;
  }
  for (let i = 0; i < flags.length; ++i) {
    if (flags[i]) {
      logsBefore += ` ${arrBefore[i]},`;
      logsAfter += ` ${arrAfter[i]},`;
      continue;
    }
    logsBefore += ` \x1b[31m${arrBefore[i]}\x1b[m,`; // color red
    logsAfter += ` \x1b[32m${arrAfter[i]}\x1b[m,`; // color green
  }
  console.log(`[#${step}] ${logsBefore.slice(0, -1) + ' ]'} -> ${logsAfter.slice(0, -1) + ' ]'}`);
}

const compareTreeDiff = () => {

};

const printTreeDiff = () => {

};

const compareGraphDiff = () => {

};

const printGraphDiff = () => {

};

export { Visualizer, compareArrDiff, printArrDiff, compareTreeDiff, printTreeDiff, compareGraphDiff, printGraphDiff };
