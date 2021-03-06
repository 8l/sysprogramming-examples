//-*- coding: utf-8-unix -*-
/**
 * (C) IT Sky Consulting GmbH 2014
 * http://www.it-sky-consulting.com/
 * Author: Karl Brodowsky
 * Date: 2014-05-20
 * License: GPL v2 (See https://de.wikipedia.org/wiki/GNU_General_Public_License )
 *
 */
object CaseClassExample {
  def main(args : Array[String]) : Unit = {
    val cce : CaseClassExample = CaseClassExample(3, 4, 5)
    println("cce=" + cce)

    f(CaseClassExample(3, 5, 7))
    f(CaseClassExample(99, 55, 77))
    f(CaseClassExample(3, 99, 1))
  }
    def f(cce : CaseClassExample) {
      cce match {
        case CaseClassExample(3, u, v) => println("u=" + u + " v=" +v);
        case CaseClassExample(_, _, _) => println("not interesting");
      }
        


  }
}

case class CaseClassExample(x : Int, y : Int, z : Int) {
}
