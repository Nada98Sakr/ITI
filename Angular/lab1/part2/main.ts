class Account {
    constructor(private Acc_No: Number, private Balance: Number) {}

    debitAmount(){
        throw new Error("Method not implemented");
    }
    creditAmount(){
        throw new Error("Method not implemented");
    }
    getBalance(){
        throw new Error("Method not implemented");
    }

}

interface IAccount{
    Date_of_opening: Date;

    addCustomer();
    removeCustomer();
}

class Saving_Account extends Account implements IAccount {
    constructor(
        private Min_balance: Number,
        public Date_of_opening: Date,
        Acc_No: Number,
        Balance: Number
    ) {
        super(Acc_No, Balance);
    }

    addCustomer() {
        throw new Error("Method not implemented");
    }
    removeCustomer() {
        throw new Error("Method not implemented");
    }
}

class Current_Account extends Account implements IAccount {
    constructor(
        private Min_balance: Number,
        public Date_of_opening: Date,
        Acc_No: Number,
        Balance: Number
    ) {
        super(Acc_No, Balance);
    }

    addCustomer() {
        throw new Error("Method not implemented");
    }
    removeCustomer() {
        throw new Error("Method not implemented");
    }
}