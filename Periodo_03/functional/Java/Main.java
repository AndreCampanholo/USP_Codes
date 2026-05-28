package Periodo_03.functional.Java;

class A {
    public void f() {
        return;
    }
}

class B extends A{
    public void g() {
        return;
    }
}

interface I {
    public void h();
    public void k();
}

class C implements I {
    public void h() {
        System.out.println("h de C");
    }

    public void k() {
        System.out.println("k de C");
    }
}

class D implements I {
    public void h() {
        System.out.println("h de D");
    }

    public void k() {
        System.out.println("k de D");
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        A a = new A();
        a.f();
        B b = new B();
        b.f();
        b.g();
        A a1 = new B();
        // B b1 = new A();
        // a1.g();
        a1.f();
        I i = new C();
        i.h();
        D d = new D();
        d.k();
    }
}