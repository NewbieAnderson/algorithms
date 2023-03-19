import { Visualizer } from '../lib/visualizer';

export default class Stack<T> implements Visualizer<T> {
  private pDatas: T[] = new Array(256);
  private mPrevDatas: T[] = this.pDatas;
  private ptop = -1;

  constructor(size?: number) {
    if (size && size > 0) {
      this.pDatas = new Array(size);
    }
    this.mPrevDatas = this.pDatas;
  }

  get prevDatas(): T[] {
    return this.mPrevDatas;
  }

  public compareDiff = (): boolean[] => {

    return [];
  };

  public printDiff = (): void => {

    return;
  };

  get capacity(): number {
    return this.pDatas.length;
  }

  get size(): number {
    return this.ptop + 1;
  };

  get top(): number {
    return this.ptop;
  }

  public push(value: T | T[]): void {
    if (!value) {
      return;
    }
    const length = value instanceof Object && value.length ? value.length : 1;
    const top = this.ptop;
    if (this.capacity >= this.size + length) {
      for (let i = 0; i < length; ++i) {
        this.pDatas[top + 1 + i] = value[i];
      }
    } else {
      this.pDatas.slice(this.ptop).concat(value, new Array(this.pDatas.length));
    }
    this.ptop += length;
  }

  public pop(count: number=1): void {
    for (let i = this.ptop; i < this.ptop - count; --i) {
      
    }
  }
}
