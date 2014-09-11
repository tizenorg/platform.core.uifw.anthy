%define __libtoolize :

Name:    anthy
Summary: A Japanese character input system library.(with dictionary)
Version: 9100h
Release: 0
URL:     http://www.sourceforge.jp/projects/anthy/
Source0: %{name}-%{version}.tar.gz
Source1001:    anthy.manifest
#
# URL: http://cannadic.oucrc.org
# Source1: cannadic-0.93.tar.gz
License: LGPL-2.1
Group: Graphics & UI Framework/Input Framework

%description
Anthy is a system for Japanese input method.
It converts Hiragana text to Kana Kanji mixed text.

%prep
%setup -q
cp %{SOURCE1001} .
#tar zxf %%{_sourcedir}/cannadic-0.93.tar.gz
#ln -s ../cannadic-0.93/gcanna.t mkanthydic
#ln -s ../cannadic-0.93/gcannaf.t mkanthydic

%build
%configure
%__make
chmod a-x COPYING

%install
rm -rf %{buildroot}
%makeinstall

%clean
rm -rf %{buildroot}

%post
/sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest %{name}.manifest
%defattr(-,root,root)
%license COPYING
%{_bindir}/*
%config %{_sysconfdir}/*
%{_datadir}/anthy
#%%{_datadir}/emacs/site-lisp/*
%{_libdir}/pkgconfig/*
%{_libdir}/libanthy*
%{_includedir}/*
#%%doc README doc
