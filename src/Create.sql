create database mailsystem;
use mailsystem;

create table Residents (
	RAddress char(7) unique not null,
    RPassword varchar(20) not null,
    NoticeTime int,
     primary key (RAddress),
     check (NoticeTime >= 0 and NoticeTime < 24)
);
create table Guards (
	GAccount varchar(20) unique not null ,
    GPassword varchar(20) not null,
    GName varchar(10),
    primary key (GAccount)
);
create table Mails (
	RId char(11) unique not null,
    MId varchar(20) unique not null,
    RType char(1) not null, -- P : package, R: regstered mail
    Remark varchar(45),
    State char(1) not null, -- L : lost, N : not taken, T : Taken, W : want take
    GivenAccount varchar(20),
    GivenDate date,
    TakenAccount varchar(20) not null,
    TakenDate date,
    MAddress char(7) not null,
    primary key (RId),
    foreign key (GivenAccount) references Guards(GAccount),
    foreign key (TakenAccount) references Guards(GAccount),
	foreign key (MAddress) references Residents(RAddress)
);
use mailsystem;
insert into Residents values('3790101', '3790101', 17);
insert into Residents values('3790102', '3790102', 17);
insert into Residents values('3790103', '3790103', 17);
insert into Residents values('3790104', '3790104', 17);
insert into Residents values('3790201', '3790201', 17);
insert into Residents values('3790202', '3790202', 17);
insert into Residents values('3790203', '3790203', 17);
insert into Residents values('3790204', '3790204', 17);
insert into Residents values('3790301', '3790301', 17);
insert into Residents values('3790302', '3790302', 17);
insert into Residents values('3790303', '3790303', 17);
insert into Residents values('3790304', '3790304', 17);
insert into Residents values('3790401', '3790401', 17);
insert into Residents values('3790402', '3790402', 17);
insert into Residents values('3790403', '3790403', 17);
insert into Residents values('3790404', '3790404', 17);
insert into Residents values('3790501', '3790501', 17);
insert into Residents values('3790502', '3790502', 17);
insert into Residents values('3790503', '3790503', 17);
insert into Residents values('3790504', '3790504', 17);
insert into Residents values('3790601', '3790601', 17);
insert into Residents values('3790602', '3790602', 17);
insert into Residents values('3790603', '3790603', 17);
insert into Residents values('3790604', '3790604', 17);
insert into Residents values('3790701', '3790701', 17);
insert into Residents values('3790702', '3790702', 17);
insert into Residents values('3790703', '3790703', 17);
insert into Residents values('3790704', '3790704', 17);
insert into Residents values('3790801', '3790801', 17);
insert into Residents values('3790802', '3790802', 17);
insert into Residents values('3790803', '3790803', 17);
insert into Residents values('3790804', '3790804', 17);
insert into Residents values('3790901', '3790901', 17);
insert into Residents values('3790902', '3790902', 17);
insert into Residents values('3790903', '3790903', 17);
insert into Residents values('3790904', '3790904', 17);
insert into Residents values('3791001', '3791001', 17);
insert into Residents values('3791002', '3791002', 17);
insert into Residents values('3791003', '3791003', 17);
insert into Residents values('3791004', '3791004', 17);
insert into Residents values('3791101', '3791101', 17);
insert into Residents values('3791102', '3791102', 17);
insert into Residents values('3791103', '3791103', 17);
insert into Residents values('3791104', '3791104', 17);
insert into Residents values('3791201', '3791201', 17);
insert into Residents values('3791202', '3791202', 17);
insert into Residents values('3791203', '3791203', 17);
insert into Residents values('3791204', '3791204', 17);
insert into Residents values('3791301', '3791301', 17);
insert into Residents values('3791302', '3791302', 17);
insert into Residents values('3791303', '3791303', 17);
insert into Residents values('3791304', '3791304', 17);
insert into Residents values('3791401', '3791401', 17);
insert into Residents values('3791402', '3791402', 17);
insert into Residents values('3791403', '3791403', 17);
insert into Residents values('3791404', '3791404', 17);
insert into Residents values('3791501', '3791501', 17);
insert into Residents values('3791502', '3791502', 17);
insert into Residents values('3791503', '3791503', 17);
insert into Residents values('3791504', '3791504', 17);
insert into Residents values('3791601', '3791601', 17);
insert into Residents values('3791602', '3791602', 17);
insert into Residents values('3791603', '3791603', 17);
insert into Residents values('3791604', '3791604', 17);
insert into Residents values('3791701', '3791701', 17);
insert into Residents values('3791702', '3791702', 17);
insert into Residents values('3791703', '3791703', 17);
insert into Residents values('3791704', '3791704', 17);
insert into Residents values('3791801', '3791801', 17);
insert into Residents values('3791802', '3791802', 17);
insert into Residents values('3791803', '3791803', 17);
insert into Residents values('3791804', '3791804', 17);
insert into Residents values('3791901', '3791901', 17);
insert into Residents values('3791902', '3791902', 17);
insert into Residents values('3791903', '3791903', 17);
insert into Residents values('3791904', '3791904', 17);
insert into Residents values('3792001', '3792001', 17);
insert into Residents values('3792002', '3792002', 17);
insert into Residents values('3792003', '3792003', 17);
insert into Residents values('3792004', '3792004', 17);
insert into Residents values('3810101', '3810101', 17);
insert into Residents values('3810102', '3810102', 17);
insert into Residents values('3810103', '3810103', 17);
insert into Residents values('3810104', '3810104', 17);
insert into Residents values('3810201', '3810201', 17);
insert into Residents values('3810202', '3810202', 17);
insert into Residents values('3810203', '3810203', 17);
insert into Residents values('3810204', '3810204', 17);
insert into Residents values('3810301', '3810301', 17);
insert into Residents values('3810302', '3810302', 17);
insert into Residents values('3810303', '3810303', 17);
insert into Residents values('3810304', '3810304', 17);
insert into Residents values('3810401', '3810401', 17);
insert into Residents values('3810402', '3810402', 17);
insert into Residents values('3810403', '3810403', 17);
insert into Residents values('3810404', '3810404', 17);
insert into Residents values('3810501', '3810501', 17);
insert into Residents values('3810502', '3810502', 17);
insert into Residents values('3810503', '3810503', 17);
insert into Residents values('3810504', '3810504', 17);
insert into Residents values('3810601', '3810601', 17);
insert into Residents values('3810602', '3810602', 17);
insert into Residents values('3810603', '3810603', 17);
insert into Residents values('3810604', '3810604', 17);
insert into Residents values('3810701', '3810701', 17);
insert into Residents values('3810702', '3810702', 17);
insert into Residents values('3810703', '3810703', 17);
insert into Residents values('3810704', '3810704', 17);
insert into Residents values('3810801', '3810801', 17);
insert into Residents values('3810802', '3810802', 17);
insert into Residents values('3810803', '3810803', 17);
insert into Residents values('3810804', '3810804', 17);
insert into Residents values('3810901', '3810901', 17);
insert into Residents values('3810902', '3810902', 17);
insert into Residents values('3810903', '3810903', 17);
insert into Residents values('3810904', '3810904', 17);
insert into Residents values('3811001', '3811001', 17);
insert into Residents values('3811002', '3811002', 17);
insert into Residents values('3811003', '3811003', 17);
insert into Residents values('3811004', '3811004', 17);
insert into Residents values('3811101', '3811101', 17);
insert into Residents values('3811102', '3811102', 17);
insert into Residents values('3811103', '3811103', 17);
insert into Residents values('3811104', '3811104', 17);
insert into Residents values('3811201', '3811201', 17);
insert into Residents values('3811202', '3811202', 17);
insert into Residents values('3811203', '3811203', 17);
insert into Residents values('3811204', '3811204', 17);
insert into Residents values('3811301', '3811301', 17);
insert into Residents values('3811302', '3811302', 17);
insert into Residents values('3811303', '3811303', 17);
insert into Residents values('3811304', '3811304', 17);
insert into Residents values('3811401', '3811401', 17);
insert into Residents values('3811402', '3811402', 17);
insert into Residents values('3811403', '3811403', 17);
insert into Residents values('3811404', '3811404', 17);
insert into Residents values('3811501', '3811501', 17);
insert into Residents values('3811502', '3811502', 17);
insert into Residents values('3811503', '3811503', 17);
insert into Residents values('3811504', '3811504', 17);
insert into Residents values('3811601', '3811601', 17);
insert into Residents values('3811602', '3811602', 17);
insert into Residents values('3811603', '3811603', 17);
insert into Residents values('3811604', '3811604', 17);
insert into Residents values('3811701', '3811701', 17);
insert into Residents values('3811702', '3811702', 17);
insert into Residents values('3811703', '3811703', 17);
insert into Residents values('3811704', '3811704', 17);
insert into Residents values('3811801', '3811801', 17);
insert into Residents values('3811802', '3811802', 17);
insert into Residents values('3811803', '3811803', 17);
insert into Residents values('3811804', '3811804', 17);
insert into Residents values('3811901', '3811901', 17);
insert into Residents values('3811902', '3811902', 17);
insert into Residents values('3811903', '3811903', 17);
insert into Residents values('3811904', '3811904', 17);
insert into Residents values('3812001', '3812001', 17);
insert into Residents values('3812002', '3812002', 17);
insert into Residents values('3812003', '3812003', 17);
insert into Residents values('3812004', '3812004', 17);
insert into Residents values('3830101', '3830101', 17);
insert into Residents values('3830102', '3830102', 17);
insert into Residents values('3830103', '3830103', 17);
insert into Residents values('3830104', '3830104', 17);
insert into Residents values('3830201', '3830201', 17);
insert into Residents values('3830202', '3830202', 17);
insert into Residents values('3830203', '3830203', 17);
insert into Residents values('3830204', '3830204', 17);
insert into Residents values('3830301', '3830301', 17);
insert into Residents values('3830302', '3830302', 17);
insert into Residents values('3830303', '3830303', 17);
insert into Residents values('3830304', '3830304', 17);
insert into Residents values('3830401', '3830401', 17);
insert into Residents values('3830402', '3830402', 17);
insert into Residents values('3830403', '3830403', 17);
insert into Residents values('3830404', '3830404', 17);
insert into Residents values('3830501', '3830501', 17);
insert into Residents values('3830502', '3830502', 17);
insert into Residents values('3830503', '3830503', 17);
insert into Residents values('3830504', '3830504', 17);
insert into Residents values('3830601', '3830601', 17);
insert into Residents values('3830602', '3830602', 17);
insert into Residents values('3830603', '3830603', 17);
insert into Residents values('3830604', '3830604', 17);
insert into Residents values('3830701', '3830701', 17);
insert into Residents values('3830702', '3830702', 17);
insert into Residents values('3830703', '3830703', 17);
insert into Residents values('3830704', '3830704', 17);
insert into Residents values('3830801', '3830801', 17);
insert into Residents values('3830802', '3830802', 17);
insert into Residents values('3830803', '3830803', 17);
insert into Residents values('3830804', '3830804', 17);
insert into Residents values('3830901', '3830901', 17);
insert into Residents values('3830902', '3830902', 17);
insert into Residents values('3830903', '3830903', 17);
insert into Residents values('3830904', '3830904', 17);
insert into Residents values('3831001', '3831001', 17);
insert into Residents values('3831002', '3831002', 17);
insert into Residents values('3831003', '3831003', 17);
insert into Residents values('3831004', '3831004', 17);
insert into Residents values('3831101', '3831101', 17);
insert into Residents values('3831102', '3831102', 17);
insert into Residents values('3831103', '3831103', 17);
insert into Residents values('3831104', '3831104', 17);
insert into Residents values('3831201', '3831201', 17);
insert into Residents values('3831202', '3831202', 17);
insert into Residents values('3831203', '3831203', 17);
insert into Residents values('3831204', '3831204', 17);
insert into Residents values('3831301', '3831301', 17);
insert into Residents values('3831302', '3831302', 17);
insert into Residents values('3831303', '3831303', 17);
insert into Residents values('3831304', '3831304', 17);
insert into Residents values('3831401', '3831401', 17);
insert into Residents values('3831402', '3831402', 17);
insert into Residents values('3831403', '3831403', 17);
insert into Residents values('3831404', '3831404', 17);
insert into Residents values('3831501', '3831501', 17);
insert into Residents values('3831502', '3831502', 17);
insert into Residents values('3831503', '3831503', 17);
insert into Residents values('3831504', '3831504', 17);
insert into Residents values('3831601', '3831601', 17);
insert into Residents values('3831602', '3831602', 17);
insert into Residents values('3831603', '3831603', 17);
insert into Residents values('3831604', '3831604', 17);
insert into Residents values('3831701', '3831701', 17);
insert into Residents values('3831702', '3831702', 17);
insert into Residents values('3831703', '3831703', 17);
insert into Residents values('3831704', '3831704', 17);
insert into Residents values('3831801', '3831801', 17);
insert into Residents values('3831802', '3831802', 17);
insert into Residents values('3831803', '3831803', 17);
insert into Residents values('3831804', '3831804', 17);
insert into Residents values('3831901', '3831901', 17);
insert into Residents values('3831902', '3831902', 17);
insert into Residents values('3831903', '3831903', 17);
insert into Residents values('3831904', '3831904', 17);
insert into Residents values('3832001', '3832001', 17);
insert into Residents values('3832002', '3832002', 17);
insert into Residents values('3832003', '3832003', 17);
insert into Residents values('3832004', '3832004', 17);
insert into Residents values('3850101', '3850101', 17);
insert into Residents values('3850102', '3850102', 17);
insert into Residents values('3850103', '3850103', 17);
insert into Residents values('3850104', '3850104', 17);
insert into Residents values('3850201', '3850201', 17);
insert into Residents values('3850202', '3850202', 17);
insert into Residents values('3850203', '3850203', 17);
insert into Residents values('3850204', '3850204', 17);
insert into Residents values('3850301', '3850301', 17);
insert into Residents values('3850302', '3850302', 17);
insert into Residents values('3850303', '3850303', 17);
insert into Residents values('3850304', '3850304', 17);
insert into Residents values('3850401', '3850401', 17);
insert into Residents values('3850402', '3850402', 17);
insert into Residents values('3850403', '3850403', 17);
insert into Residents values('3850404', '3850404', 17);
insert into Residents values('3850501', '3850501', 17);
insert into Residents values('3850502', '3850502', 17);
insert into Residents values('3850503', '3850503', 17);
insert into Residents values('3850504', '3850504', 17);
insert into Residents values('3850601', '3850601', 17);
insert into Residents values('3850602', '3850602', 17);
insert into Residents values('3850603', '3850603', 17);
insert into Residents values('3850604', '3850604', 17);
insert into Residents values('3850701', '3850701', 17);
insert into Residents values('3850702', '3850702', 17);
insert into Residents values('3850703', '3850703', 17);
insert into Residents values('3850704', '3850704', 17);
insert into Residents values('3850801', '3850801', 17);
insert into Residents values('3850802', '3850802', 17);
insert into Residents values('3850803', '3850803', 17);
insert into Residents values('3850804', '3850804', 17);
insert into Residents values('3850901', '3850901', 17);
insert into Residents values('3850902', '3850902', 17);
insert into Residents values('3850903', '3850903', 17);
insert into Residents values('3850904', '3850904', 17);
insert into Residents values('3851001', '3851001', 17);
insert into Residents values('3851002', '3851002', 17);
insert into Residents values('3851003', '3851003', 17);
insert into Residents values('3851004', '3851004', 17);
insert into Residents values('3851101', '3851101', 17);
insert into Residents values('3851102', '3851102', 17);
insert into Residents values('3851103', '3851103', 17);
insert into Residents values('3851104', '3851104', 17);
insert into Residents values('3851201', '3851201', 17);
insert into Residents values('3851202', '3851202', 17);
insert into Residents values('3851203', '3851203', 17);
insert into Residents values('3851204', '3851204', 17);
insert into Residents values('3851301', '3851301', 17);
insert into Residents values('3851302', '3851302', 17);
insert into Residents values('3851303', '3851303', 17);
insert into Residents values('3851304', '3851304', 17);
insert into Residents values('3851401', '3851401', 17);
insert into Residents values('3851402', '3851402', 17);
insert into Residents values('3851403', '3851403', 17);
insert into Residents values('3851404', '3851404', 17);
insert into Residents values('3851501', '3851501', 17);
insert into Residents values('3851502', '3851502', 17);
insert into Residents values('3851503', '3851503', 17);
insert into Residents values('3851504', '3851504', 17);
insert into Residents values('3851601', '3851601', 17);
insert into Residents values('3851602', '3851602', 17);
insert into Residents values('3851603', '3851603', 17);
insert into Residents values('3851604', '3851604', 17);
insert into Residents values('3851701', '3851701', 17);
insert into Residents values('3851702', '3851702', 17);
insert into Residents values('3851703', '3851703', 17);
insert into Residents values('3851704', '3851704', 17);
insert into Residents values('3851801', '3851801', 17);
insert into Residents values('3851802', '3851802', 17);
insert into Residents values('3851803', '3851803', 17);
insert into Residents values('3851804', '3851804', 17);
insert into Residents values('3851901', '3851901', 17);
insert into Residents values('3851902', '3851902', 17);
insert into Residents values('3851903', '3851903', 17);
insert into Residents values('3851904', '3851904', 17);
insert into Residents values('3852001', '3852001', 17);
insert into Residents values('3852002', '3852002', 17);
insert into Residents values('3852003', '3852003', 17);
insert into Residents values('3852004', '3852004', 17);
insert into Residents values('3890101', '3890101', 17);
insert into Residents values('3890102', '3890102', 17);
insert into Residents values('3890103', '3890103', 17);
insert into Residents values('3890104', '3890104', 17);
insert into Residents values('3890201', '3890201', 17);
insert into Residents values('3890202', '3890202', 17);
insert into Residents values('3890203', '3890203', 17);
insert into Residents values('3890204', '3890204', 17);
insert into Residents values('3890301', '3890301', 17);
insert into Residents values('3890302', '3890302', 17);
insert into Residents values('3890303', '3890303', 17);
insert into Residents values('3890304', '3890304', 17);
insert into Residents values('3890401', '3890401', 17);
insert into Residents values('3890402', '3890402', 17);
insert into Residents values('3890403', '3890403', 17);
insert into Residents values('3890404', '3890404', 17);
insert into Residents values('3890501', '3890501', 17);
insert into Residents values('3890502', '3890502', 17);
insert into Residents values('3890503', '3890503', 17);
insert into Residents values('3890504', '3890504', 17);
insert into Residents values('3890601', '3890601', 17);
insert into Residents values('3890602', '3890602', 17);
insert into Residents values('3890603', '3890603', 17);
insert into Residents values('3890604', '3890604', 17);
insert into Residents values('3890701', '3890701', 17);
insert into Residents values('3890702', '3890702', 17);
insert into Residents values('3890703', '3890703', 17);
insert into Residents values('3890704', '3890704', 17);
insert into Residents values('3890801', '3890801', 17);
insert into Residents values('3890802', '3890802', 17);
insert into Residents values('3890803', '3890803', 17);
insert into Residents values('3890804', '3890804', 17);
insert into Residents values('3890901', '3890901', 17);
insert into Residents values('3890902', '3890902', 17);
insert into Residents values('3890903', '3890903', 17);
insert into Residents values('3890904', '3890904', 17);
insert into Residents values('3891001', '3891001', 17);
insert into Residents values('3891002', '3891002', 17);
insert into Residents values('3891003', '3891003', 17);
insert into Residents values('3891004', '3891004', 17);
insert into Residents values('3891101', '3891101', 17);
insert into Residents values('3891102', '3891102', 17);
insert into Residents values('3891103', '3891103', 17);
insert into Residents values('3891104', '3891104', 17);
insert into Residents values('3891201', '3891201', 17);
insert into Residents values('3891202', '3891202', 17);
insert into Residents values('3891203', '3891203', 17);
insert into Residents values('3891204', '3891204', 17);
insert into Residents values('3891301', '3891301', 17);
insert into Residents values('3891302', '3891302', 17);
insert into Residents values('3891303', '3891303', 17);
insert into Residents values('3891304', '3891304', 17);
insert into Residents values('3891401', '3891401', 17);
insert into Residents values('3891402', '3891402', 17);
insert into Residents values('3891403', '3891403', 17);
insert into Residents values('3891404', '3891404', 17);
insert into Residents values('3891501', '3891501', 17);
insert into Residents values('3891502', '3891502', 17);
insert into Residents values('3891503', '3891503', 17);
insert into Residents values('3891504', '3891504', 17);
insert into Residents values('3891601', '3891601', 17);
insert into Residents values('3891602', '3891602', 17);
insert into Residents values('3891603', '3891603', 17);
insert into Residents values('3891604', '3891604', 17);
insert into Residents values('3891701', '3891701', 17);
insert into Residents values('3891702', '3891702', 17);
insert into Residents values('3891703', '3891703', 17);
insert into Residents values('3891704', '3891704', 17);
insert into Residents values('3891801', '3891801', 17);
insert into Residents values('3891802', '3891802', 17);
insert into Residents values('3891803', '3891803', 17);
insert into Residents values('3891804', '3891804', 17);
insert into Residents values('3891901', '3891901', 17);
insert into Residents values('3891902', '3891902', 17);
insert into Residents values('3891903', '3891903', 17);
insert into Residents values('3891904', '3891904', 17);
insert into Residents values('3892001', '3892001', 17);
insert into Residents values('3892002', '3892002', 17);
insert into Residents values('3892003', '3892003', 17);
insert into Residents values('3892004', '3892004', 17);
insert into Residents values('3910101', '3910101', 17);
insert into Residents values('3910102', '3910102', 17);
insert into Residents values('3910103', '3910103', 17);
insert into Residents values('3910104', '3910104', 17);
insert into Residents values('3910201', '3910201', 17);
insert into Residents values('3910202', '3910202', 17);
insert into Residents values('3910203', '3910203', 17);
insert into Residents values('3910204', '3910204', 17);
insert into Residents values('3910301', '3910301', 17);
insert into Residents values('3910302', '3910302', 17);
insert into Residents values('3910303', '3910303', 17);
insert into Residents values('3910304', '3910304', 17);
insert into Residents values('3910401', '3910401', 17);
insert into Residents values('3910402', '3910402', 17);
insert into Residents values('3910403', '3910403', 17);
insert into Residents values('3910404', '3910404', 17);
insert into Residents values('3910501', '3910501', 17);
insert into Residents values('3910502', '3910502', 17);
insert into Residents values('3910503', '3910503', 17);
insert into Residents values('3910504', '3910504', 17);
insert into Residents values('3910601', '3910601', 17);
insert into Residents values('3910602', '3910602', 17);
insert into Residents values('3910603', '3910603', 17);
insert into Residents values('3910604', '3910604', 17);
insert into Residents values('3910701', '3910701', 17);
insert into Residents values('3910702', '3910702', 17);
insert into Residents values('3910703', '3910703', 17);
insert into Residents values('3910704', '3910704', 17);
insert into Residents values('3910801', '3910801', 17);
insert into Residents values('3910802', '3910802', 17);
insert into Residents values('3910803', '3910803', 17);
insert into Residents values('3910804', '3910804', 17);
insert into Residents values('3910901', '3910901', 17);
insert into Residents values('3910902', '3910902', 17);
insert into Residents values('3910903', '3910903', 17);
insert into Residents values('3910904', '3910904', 17);
insert into Residents values('3911001', '3911001', 17);
insert into Residents values('3911002', '3911002', 17);
insert into Residents values('3911003', '3911003', 17);
insert into Residents values('3911004', '3911004', 17);
insert into Residents values('3911101', '3911101', 17);
insert into Residents values('3911102', '3911102', 17);
insert into Residents values('3911103', '3911103', 17);
insert into Residents values('3911104', '3911104', 17);
insert into Residents values('3911201', '3911201', 17);
insert into Residents values('3911202', '3911202', 17);
insert into Residents values('3911203', '3911203', 17);
insert into Residents values('3911204', '3911204', 17);
insert into Residents values('3911301', '3911301', 17);
insert into Residents values('3911302', '3911302', 17);
insert into Residents values('3911303', '3911303', 17);
insert into Residents values('3911304', '3911304', 17);
insert into Residents values('3911401', '3911401', 17);
insert into Residents values('3911402', '3911402', 17);
insert into Residents values('3911403', '3911403', 17);
insert into Residents values('3911404', '3911404', 17);
insert into Residents values('3911501', '3911501', 17);
insert into Residents values('3911502', '3911502', 17);
insert into Residents values('3911503', '3911503', 17);
insert into Residents values('3911504', '3911504', 17);
insert into Residents values('3911601', '3911601', 17);
insert into Residents values('3911602', '3911602', 17);
insert into Residents values('3911603', '3911603', 17);
insert into Residents values('3911604', '3911604', 17);
insert into Residents values('3911701', '3911701', 17);
insert into Residents values('3911702', '3911702', 17);
insert into Residents values('3911703', '3911703', 17);
insert into Residents values('3911704', '3911704', 17);
insert into Residents values('3911801', '3911801', 17);
insert into Residents values('3911802', '3911802', 17);
insert into Residents values('3911803', '3911803', 17);
insert into Residents values('3911804', '3911804', 17);
insert into Residents values('3911901', '3911901', 17);
insert into Residents values('3911902', '3911902', 17);
insert into Residents values('3911903', '3911903', 17);
insert into Residents values('3911904', '3911904', 17);
insert into Residents values('3912001', '3912001', 17);
insert into Residents values('3912002', '3912002', 17);
insert into Residents values('3912003', '3912003', 17);
insert into Residents values('3912004', '3912004', 17);
insert into Residents values('9999999', '9999999', 17);