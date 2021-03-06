# DesignPatterns
<hr>
<p>
  Learning Design Patterns in C++ and will try to use them within other languages.<br>
  <h3>Learning resources:</h3><br>
  <h3>Head First Design Patterns</h3>
  Bert Bates, Kathy Sierra, Eric Freeman, Elisabeth Robson
  <h3>Elements of Reusable Object-Oriented Software</h3>
   Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides
</p>
<hr>
  <h3>Description:</h3>
 Wikipedia:
 <p>
 software design pattern is a general, reusable solution to a commonly occurring problem within a given context in software design. It is  not a finished design that can be transformed directly into source or machine code. It is a description or template for how to solve a problem that can be used in many different situations. Design patterns are formalized best practices that the programmer can use to solve common problems when designing an application or system. Design patterns were originally grouped into the categories: creational patterns, structural patterns, and behavioral patterns, and described using the concepts of delegation, aggregation, and consultation.
</p>
<h3>Design patterns catalog:</h3><hr>
<h2>Behavioral</h2>
<table>
  <tr>
    <th>
      Name&link
    </th>
    <th>
      Description
    </th>
    <th>
      Diagram
    </th>
  </tr>
  <tr>
    <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/Strategy.h">Strategy</a></td>
    <td>allows one of a family of algorithms to be selected on-the-fly at runtime.</td>
    <td><a href="https://www.dofactory.com/images/diagrams/net/strategy.gif">Click</a></td>
  </tr>
  <tr>
    <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/Observer.h">Observer</a></td>
    <td>maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.</td>
    <td><a href="https://www.bogotobogo.com/DesignPatterns/images/observer/observer_pattern.gif">Click</a></td>
  </tr>
    <tr>
      <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/Command.h">Command</a></td>
      <td>Encapsulate a request as an object, thereby letting you parametrize clients with different requests, queue or log requests, and support undoable operations.</td>
      <td><a href="https://www.dofactory.com/images/diagrams/net/command.gif">Click</a></td>
    </tr>
</table>
<h2>Structural</h2>
<table>
  <tr>
    <th>
      Name&link
    </th>
    <th>
      Description
    </th>
    <th>
      Diagram
    </th>
  </tr>
  <tr>
    <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/Decorator.h">Decorator</a></td>
    <td>allows behavior to be added to an individual object, dynamically, without affecting the behavior of other objects from the same class</td>
    <td><a href="https://static.dzone.com/dz1/dz-files/decorator_pattern_0.png">Click</a></td>
  </tr>
</table>
<h2>Creational</h2>
<table>
  <tr>
    <th>
      Name&link
    </th>
    <th>
      Description
    </th>
    <th>
      Diagram
    </th>
  </tr>
  <tr>
    <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/SimpleFactory.h">SimpleFactoryMethod</a></td>
    <td>Allows interfaces for creating objects without exposing the object creation logic to the client</td>
    <td><a href="https://4.bp.blogspot.com/-eCBmRuAvg6U/WlhH_TPitYI/AAAAAAAABqE/BTb6rlDnA5k_GPKbAyMo6JmIHUK3oBa8wCLcBGAs/s1600/factory_design_pattern.png">Click</a></td>
  </tr>
    <tr>
      <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/FactoryMethod.h">FactoryMethod</a></td>
      <td>Allows interfaces for creating objects, but allow subclasses to determine which class to instantiate.</td>
      <td><a href="http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/images/FactoryMethod.jpg">Click</a></td>
    </tr>
    <tr>
      <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/AbstractFactory.h">AbstractFactoryPattern</a></td>
      <td>Provide an interface for creating families of related or dependent objects without specifying their concrete classes.</td>
      <td><a href="https://www.uml-diagrams.org/examples/class-example-abstract-factory.png">Click</a></td>
    </tr>
        <tr>
          <td><a href="https://github.com/Lukas713/DesignPatterns/blob/master/Singleton.h">Singleton</a></td>
          <td>Ensure a class has only one instance, and provide a global point of access to it.</td>
          <td><a href="https://www.tutorialspoint.com/design_pattern/images/singleton_pattern_uml_diagram.jpg">Click</a></td>
        </tr>
</table>
