//-*- coding: utf-8-unix -*-
/**
 * (C) IT Sky Consulting GmbH 2014
 * http://www.it-sky-consulting.com/
 * Author: Karl Brodowsky
 * Date: 2014-05-20
 * License: GPL v2 (See https://de.wikipedia.org/wiki/GNU_General_Public_License )
 *
 */
// import scala.collection.immutable.Map
import scala.collection.mutable.HashMap
import scala.collection.immutable.Map

object MapExample {
  def main(args : Array[String]) : Unit = {
    val hm : HashMap[Int,Int] = HashMap(2 -> 4, 3 -> 9, 5 -> 25, 7 -> 49)
    println("hm=" + hm)
    hm(11)=121
    println("hm=" + hm)
    hm(13)=169
    println("hm=" + hm)
    val m : Map[Int,Int] = Map(1 -> 3, 2->8, 4->24, 6->48, 10->120)
    println("m=" + m)
    // not possible:
    // m(12)=168
    // but this works:
    val m12 = m +(12->168)
    println("m=" + m)
    println("m12=" + m12)
    val m1214 = m +(12->168, 16->288)
    println("m=" + m)
    println("m12=" + m12)
    println("m1214=" + m1214)
  }
}
